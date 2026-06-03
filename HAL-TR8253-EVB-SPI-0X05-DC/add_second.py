"""Add 0x6001/0x7001 (128 UINT16 each) to existing 128 SSC-DeviceObjects.h."""
import shutil, re

proj = r'd:/YPC/Desktop/Keil5 Project/HAL-TR8253-EVB-SPI-0X05-DC'
factory = r'd:/YPC/Desktop/工作资料/资料/TR8253_EVB软件开发资料_REV3.5/TR8253_EVB_demo_REV3.5/HAL-TR8253-EVB-SPI-0X05-DC'

N1 = 128
N2 = 128
TOTAL = N1 + N2

with open(f'{proj}/SSC/SSC-DeviceObjects.h', 'rb') as f:
    c = f.read().decode('latin-1')

# ── 1. Build 0x6001 object definition ──
obj_6001 = '''
/******************************************************************************
*                    Object 0x6001 : Tx Uint16 (128)
******************************************************************************/
#ifdef _OBJD_
OBJCONST TSDOINFOENTRYDESC OBJMEM asEntryDesc0x6001[] = {
\t{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ },
'''
for i in range(1, N2+1):
    obj_6001 += f'\t{{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }}'
    obj_6001 += '' if i == N2 else ','
    obj_6001 += '\n'
obj_6001 += '''};
OBJCONST UCHAR OBJMEM aName0x6001[] = "TxU16\\000\\377";
#endif
#ifndef _SSC_DEVICE_OBJECTS_H_
typedef struct OBJ_STRUCT_PACKED_START {
\tUINT16 u16SubIndex0;
'''
for i in range(1, N2+1):
    obj_6001 += f'\tUINT16 DI{i};\n'
obj_6001 += '''} OBJ_STRUCT_PACKED_END
\tTOBJ6001;
#endif
PROTO TOBJ6001 TxU16_0x6001
#if defined(_SSC_DEVICE_) && (_SSC_DEVICE_ == 1)
={''' + str(N2) + ',' + '0,'*(N2-1) + '0}\n#endif\n;\n/** @}*/\n'

# ── 2. Build 0x7001 ──
obj_7001 = obj_6001.replace('0x6001', '0x7001')
obj_7001 = obj_7001.replace('TxU16', 'RxU16')
obj_7001 = obj_7001.replace('TOBJ6001', 'TOBJ7001')
obj_7001 = obj_7001.replace('ACCESS_READ | OBJACCESS_TXPDOMAPPING', 'ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING')
obj_7001 = obj_7001.replace('\tUINT16 DI', '\tUINT16 DO')

# ── 3. Insert before Object 0xF008 ──
ins = c.find('Object 0xF008')
c = c[:ins] + obj_6001 + obj_7001 + c[ins:]

# ── 4. Extend 0x1600/0x1A00 structs ──
# Current: SI1..SI128. Need SI1..SI256
si_extra = '\r\n'.join([f'\tUINT32 SI{i};' for i in range(N1+1, TOTAL+1)])
c = re.sub(r'(UINT32 SI128;\r\n)(\} OBJ_STRUCT_PACKED_END\r\nTOBJ1600;)',
           r'\1' + si_extra + r'\r\n\2', c)
c = re.sub(r'(UINT32 SI128;\r\n)(\} OBJ_STRUCT_PACKED_END\r\nTOBJ1A00;)',
           r'\1' + si_extra + r'\r\n\2', c)

# ── 5. Extend asEntryDesc0x1600/0x1A00 ──
si_desc = ','.join(['\t{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_RXPDOMAPPING }' for _ in range(N2)])
c = re.sub(r'(asEntryDesc0x1600\[\] = \{.*?\r\n)\};',
           r'\1' + si_desc + r'\r\n};', c, count=1, flags=re.DOTALL)
c = re.sub(r'(asEntryDesc0x1A00\[\] = \{.*?\r\n)\};',
           r'\1' + si_desc + r'\r\n};', c, count=1, flags=re.DOTALL)

# ── 6. Add Target Values for 0x6001/0x7001 ──
rx_extra = ','.join([f'0x7001{i:02X}10' for i in range(1, N2+1)])
tx_extra = ','.join([f'0x6001{i:02X}10' for i in range(1, N2+1)])
c = c.replace('0x70008010}', '0x70008010,' + rx_extra + '}')
c = c.replace('0x60008010}', '0x60008010,' + tx_extra + '}')

# ── 7. Update DOUnit20x1600/DIUnit10x1A00 init counts ──
c = c.replace('={128,0x70000110', '={' + str(TOTAL) + ',0x70000110')
c = c.replace('={128,0x60000110', '={' + str(TOTAL) + ',0x60000110')

# ── 8. Update ApplicationObjDic ──
c = c.replace('PDOMAPPING , 128 |', 'PDOMAPPING , ' + str(TOTAL) + ' |')
c = c.replace('{NULL , NULL ,  0xF008 ,',
              '{NULL , NULL ,  0x6001 , {DEFTYPE_RECORD , ' + str(N2) + ' | (OBJCODE_REC << 8)} , asEntryDesc0x6001 , aName0x6001 , &TxU16_0x6001 , NULL , NULL , 0x0000 },\n'
              '{NULL , NULL ,  0x7001 , {DEFTYPE_RECORD , ' + str(N2) + ' | (OBJCODE_REC << 8)} , asEntryDesc0x7001 , aName0x7001 , &RxU16_0x7001 , NULL , NULL , 0x0000 },\n'
              '{NULL , NULL ,  0xF008 ,')

with open(f'{proj}/SSC/SSC-DeviceObjects.h', 'wb') as f:
    f.write(c.encode('latin-1'))

# ── 9. Sync other files ──
# Config
hdr = f'#ifndef _ECAT_PDO_CONFIG_H_\n#define _ECAT_PDO_CONFIG_H_\n#define ECAT_TX_BOOL_COUNT      0\n#define ECAT_TX_UINT16_COUNT    {TOTAL}\n#define ECAT_RX_BOOL_COUNT      0\n#define ECAT_RX_UINT16_COUNT    {TOTAL}\n#define ECAT_BOOL_BYTES         (((ECAT_TX_BOOL_COUNT) + 7U) / 8U)\n#define ECAT_UINT16_BYTES       ((ECAT_TX_UINT16_COUNT) * 2U)\n#define ECAT_PDO_TOTAL_BYTES    (ECAT_BOOL_BYTES + ECAT_UINT16_BYTES)\n#endif\n'
for d in ['/ECAT', '/SSC', '/HARDWARE']:
    with open(f'{proj}{d}/ecat_pdo_config.h', 'w') as f: f.write(hdr)

# Application.c
with open(f'{proj}/HARDWARE/Application.c', 'rb') as f:
    ac = f.read().decode('utf-8', errors='replace')
old_tx = 'UINT16 *pInputs = (UINT16 *)pData;\n\t*pInputs++ = *(&DIUnit10x6000.u16SubIndex0 + 1);'
new_tx = (f'memcpy(pData, &DIUnit10x6000.u16SubIndex0 + 1, {N1*2});\n'
          f'\tmemcpy((uint8_t*)pData + {N1*2}, &TxU16_0x6001.u16SubIndex0 + 1, {N2*2});')
if old_tx in ac:
    ac = ac.replace(old_tx, new_tx)
else:
    ac = ac.replace('memcpy(pData, &DIUnit10x6000.u16SubIndex0 + 1, ECAT_PDO_TOTAL_BYTES);', new_tx)

old_rx = '*(&DOUnit20x7000.u16SubIndex0 + 1)= *pData;'
new_rx = (f'memcpy(&DOUnit20x7000.u16SubIndex0 + 1, pData, {N1*2});\n'
          f'\tmemcpy(&RxU16_0x7001.u16SubIndex0 + 1, (uint8_t*)pData + {N1*2}, {N2*2});')
if old_rx in ac:
    ac = ac.replace(old_rx, new_rx)
else:
    ac = ac.replace('memcpy(&DOUnit20x7000.u16SubIndex0 + 1, pData, ECAT_PDO_TOTAL_BYTES);', new_rx)

with open(f'{proj}/HARDWARE/Application.c', 'wb') as f:
    f.write(ac.encode('utf-8'))

# XML
shutil.copy(f'{factory}/TRI_SPI_DC.xml', f'{proj}/')
with open(f'{proj}/TRI_SPI_DC.xml', encoding='utf-8') as f:
    xml = f.read()
total_bytes = TOTAL * 2
xml = re.sub(r'<RxPdo[^>]*>.*?</RxPdo>',
             f'<RxPdo Fixed="true" Mandatory="true" Sm="2"><Index>#x1600</Index><Name>RxPDO</Name></RxPdo>',
             xml, flags=re.DOTALL)
xml = re.sub(r'<TxPdo[^>]*>.*?</TxPdo>',
             f'<TxPdo Fixed="true" Mandatory="true" Sm="3"><Index>#x1A00</Index><Name>TxPDO</Name></TxPdo>',
             xml, flags=re.DOTALL)
for i in range(1, N1+1):
    xml = xml.replace('</RxPdo>', f'<Entry><Index>#x7000</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>R0_{i}</Name><DataType>UINT</DataType></Entry>\n</RxPdo>')
    xml = xml.replace('</TxPdo>', f'<Entry><Index>#x6000</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>T0_{i}</Name><DataType>UINT</DataType></Entry>\n</TxPdo>')
for i in range(1, N2+1):
    xml = xml.replace('</RxPdo>', f'<Entry><Index>#x7001</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>R1_{i}</Name><DataType>UINT</DataType></Entry>\n</RxPdo>')
    xml = xml.replace('</TxPdo>', f'<Entry><Index>#x6001</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>T1_{i}</Name><DataType>UINT</DataType></Entry>\n</TxPdo>')
xml = xml.replace('DefaultSize="2" StartAddress="#x1400"', f'DefaultSize="{total_bytes}" StartAddress="#x1400"')
xml = xml.replace('DefaultSize="2" StartAddress="#x1800"', f'DefaultSize="{total_bytes}" StartAddress="#x1800"')
with open(f'{proj}/TRI_SPI_DC.xml', 'w', encoding='utf-8') as f:
    f.write(xml)

print(f'{N1}+{N2}={TOTAL} UINT16, {total_bytes} bytes')
