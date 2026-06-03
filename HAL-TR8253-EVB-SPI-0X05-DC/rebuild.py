import shutil, re
factory = r'd:/YPC/Desktop/工作资料/资料/TR8253_EVB软件开发资料_REV3.5/TR8253_EVB_demo_REV3.5/HAL-TR8253-EVB-SPI-0X05-DC'
proj = r'd:/YPC/Desktop/Keil5 Project/HAL-TR8253-EVB-SPI-0X05-DC'
N = 128

for f in ['SSC/SSC-DeviceObjects.h','SSC/SSC-Device.c','HARDWARE/Application.c','Core/Src/main.c','TRI_SPI_DC.xml','SSC/ecat_def.h']:
    shutil.copy(f'{factory}/{f}', f'{proj}/{f}')

p = f'{proj}/SSC/ecat_def.h'
with open(p) as f: c = f.read()
c = re.sub(r'(MAX_PD_INPUT_SIZE\s+)(0x[0-9A-Fa-f]+)', r'\g<1>0x400', c)
c = re.sub(r'(MAX_PD_OUTPUT_SIZE\s+)(0x[0-9A-Fa-f]+)', r'\g<1>0x400', c)
with open(p,'w') as f: f.write(c)

hdr = f'#ifndef _ECAT_PDO_CONFIG_H_\n#define _ECAT_PDO_CONFIG_H_\n#define ECAT_TX_BOOL_COUNT      0\n#define ECAT_TX_UINT16_COUNT    {N}\n#define ECAT_RX_BOOL_COUNT      0\n#define ECAT_RX_UINT16_COUNT    {N}\n#define ECAT_BOOL_BYTES         (((ECAT_TX_BOOL_COUNT) + 7U) / 8U)\n#define ECAT_UINT16_BYTES       ((ECAT_TX_UINT16_COUNT) * 2U)\n#define ECAT_PDO_TOTAL_BYTES    (ECAT_BOOL_BYTES + ECAT_UINT16_BYTES)\n#endif\n'
for d in ['/ECAT','/SSC','/HARDWARE']:
    with open(f'{proj}{d}/ecat_pdo_config.h','w') as f: f.write(hdr)

with open(f'{proj}/Core/Src/main.c') as f: mc = f.read()
mc = mc.replace('#include "Application.h"', '#include "Application.h"\n#include "ecat_pdo_config.h"')
mc = mc.replace('HW_Init();\n\tMainInit();', 'HW_Init();\n\tHW_EscWriteWord(ECAT_PDO_TOTAL_BYTES, 0x0812);\n\tHW_EscWriteWord(ECAT_PDO_TOTAL_BYTES, 0x081A);\n\tMainInit();')
with open(f'{proj}/Core/Src/main.c','w') as f: f.write(mc)

with open(f'{proj}/SSC/SSC-Device.c') as f: dc = f.read()
dc = dc.replace('#include "ecat_def.h"', '#include "ecat_def.h"\n#include "ecat_pdo_config.h"')
dc = re.sub(r'UINT16 APPL_GenerateMapping.*?\n\}', 'UINT16 APPL_GenerateMapping(UINT16 *pInputSize,UINT16 *pOutputSize)\n{\n    *pInputSize  = ECAT_PDO_TOTAL_BYTES;\n    *pOutputSize = ECAT_PDO_TOTAL_BYTES;\n    return ALSTATUSCODE_NOERROR;\n}', dc, flags=re.DOTALL)
with open(f'{proj}/SSC/SSC-Device.c','w') as f: f.write(dc)

with open(f'{proj}/SSC/SSC-DeviceObjects.h','rb') as f: c = f.read().decode('latin-1')
i1=c.find('BOOLEAN(DI1);'); i2=c.find('BOOLEAN(DI16);')
c=c[:i1]+'UINT16 val;\r\n'+'\r\n'.join([f'UINT16 DI{i};' for i in range(2,N+1)])+c[i2+len('BOOLEAN(DI16); /* Subindex16 - DI 16 */\r\n'):]
i1=c.find('BOOLEAN(DO1);'); i2=c.find('BOOLEAN(DO16);')
c=c[:i1]+'UINT16 val;\r\n'+'\r\n'.join([f'UINT16 DO{i};' for i in range(2,N+1)])+c[i2+len('BOOLEAN(DO16); /* Subindex16 - DO 16 */\r\n'):]
i1=c.find('UINT32 SI1;'); i2=c.find('UINT32 SI16; /* Subindex16 -  */')
cut=i2+len('UINT32 SI16; /* Subindex16 -  */\r\n')
si='\r\n'.join([f'UINT32 SI{i};' for i in range(1,N+1)]); c=c[:i1]+si+c[cut:]
i1=c.find('UINT32 SI1;',c.find('UINT32 SI1;')+1); i2=c.find('UINT32 SI16;',i1)
cut=i2+len('UINT32 SI16; /* Subindex16 -  */\r\n'); c=c[:i1]+si+c[cut:]

def mk(nm,s0,e,nn): return nm+'[] = {\r\n\t'+s0+',\r\n\t'+',\r\n\t'.join([e]*nn)+'\r\n};\r\n'
for nm in ['0x6000','0x7000','0x1600','0x1A00']:
    c=re.sub(r'asEntryDesc'+nm+r'\[\]\s*=\s*\{.*?\r\n\};','',c,flags=re.DOTALL)
ins=c.find('Object 0xF008')
c=c[:ins]+mk('asEntryDesc0x6000','{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }','{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READ | OBJACCESS_TXPDOMAPPING }',N)+mk('asEntryDesc0x7000','{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }','{ DEFTYPE_UNSIGNED16 , 0x10 , ACCESS_READWRITE | OBJACCESS_RXPDOMAPPING }',N)+mk('asEntryDesc0x1600','{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }','{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_RXPDOMAPPING }',N)+mk('asEntryDesc0x1A00','{ DEFTYPE_UNSIGNED8 , 0x8 , ACCESS_READ }','{ DEFTYPE_UNSIGNED32 , 0x20 , ACCESS_READ | OBJACCESS_RXPDOMAPPING }',N)+c[ins:]
c=c.replace('0x70000101,0x70000201,0x70000301,0x70000401,0x70000501,0x70000601,0x70000701,0x70000801,0x70000901,0x70000A01,0x70000B01,0x70000C01,0x70000D01,0x70000E01,0x70000F01,0x70001001}',','.join([f'0x7000{i:02X}10' for i in range(1,N+1)]))
c=c.replace('0x60000101,0x60000201,0x60000301,0x60000401,0x60000501,0x60000601,0x60000701,0x60000801,0x60000901,0x60000A01,0x60000B01,0x60000C01,0x60000D01,0x60000E01,0x60000F01,0x60001001}',','.join([f'0x6000{i:02X}10' for i in range(1,N+1)]))
c=c.replace('={16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}','={'+str(N)+','+'0,'*(N-1)+'0}')
c=c.replace('={16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}','={'+str(N)+','+'0,'*(N-1)+'0}')
c=c.replace('={16,','={'+str(N)+',')
c=c.replace('RECORD , 16 |','RECORD , '+str(N)+' |')
c=c.replace('PDOMAPPING , 16 |','PDOMAPPING , '+str(N)+' |')
for m in re.finditer(r'(=\{(170|'+str(N)+r'),[0-9A-Fa-fx,]+?)(\r\n[ \t]*#endif)', c):
    c=c.replace(m.group(0),m.group(1)+'}'+m.group(2))
with open(f'{proj}/SSC/SSC-DeviceObjects.h','wb') as f: f.write(c.encode('latin-1'))

with open(f'{proj}/HARDWARE/Application.c','rb') as f: ac=f.read().decode('utf-8',errors='replace')
ac=ac.replace('#include "Application.h"','#include <string.h>\n#include "ecat_pdo_config.h"\n#include "Application.h"')
ac=ac.replace('UINT16 *pInputs = (UINT16 *)pData;\n\t*pInputs++ = *(&DIUnit10x6000.u16SubIndex0 + 1);','memcpy(pData, &DIUnit10x6000.u16SubIndex0 + 1, ECAT_PDO_TOTAL_BYTES);')
ac=ac.replace('*(&DOUnit20x7000.u16SubIndex0 + 1)= *pData;','memcpy(&DOUnit20x7000.u16SubIndex0 + 1, pData, ECAT_PDO_TOTAL_BYTES);')
ol='DOCH0 = DOUnit20x7000.DO1;\r\n\tDOCH1 = DOUnit20x7000.DO2;\r\n\tDOCH2 = DOUnit20x7000.DO3;\r\n\tDOCH3 = DOUnit20x7000.DO4;\r\n\tDOCH4 = DOUnit20x7000.DO5;\r\n\tDOCH5 = DOUnit20x7000.DO6;\r\n\tDOCH6 = DOUnit20x7000.DO7;\r\n\tDOCH7 = DOUnit20x7000.DO8;\r\n\r\n\tDOCH8 = DOUnit20x7000.DO9;\r\n\tDOCH9 = DOUnit20x7000.DO10;\r\n\tDOCH10 = DOUnit20x7000.DO11;\r\n\tDOCH11 = DOUnit20x7000.DO12;\r\n\tDOCH12 = DOUnit20x7000.DO13;\r\n\tDOCH13 = DOUnit20x7000.DO14;\r\n\tDOCH14 = DOUnit20x7000.DO15;\r\n\tDOCH15 = DOUnit20x7000.DO16;'
nl='UINT16 v = DOUnit20x7000.val;\r\n\tDOCH0=(v>>0)&1; DOCH1=(v>>1)&1; DOCH2=(v>>2)&1; DOCH3=(v>>3)&1;\r\n\tDOCH4=(v>>4)&1; DOCH5=(v>>5)&1; DOCH6=(v>>6)&1; DOCH7=(v>>7)&1;\r\n\tDOCH8=(v>>8)&1; DOCH9=(v>>9)&1; DOCH10=(v>>10)&1; DOCH11=(v>>11)&1;\r\n\tDOCH12=(v>>12)&1; DOCH13=(v>>13)&1; DOCH14=(v>>14)&1; DOCH15=(v>>15)&1;'
ac=ac.replace(ol,nl); ac=ac.replace('sizeof(TOBJ7000)','ECAT_PDO_TOTAL_BYTES')
with open(f'{proj}/HARDWARE/Application.c','wb') as f: f.write(ac.encode('utf-8'))

shutil.copy(f'{factory}/TRI_SPI_DC.xml',f'{proj}/')
with open(f'{proj}/TRI_SPI_DC.xml',encoding='utf-8') as f: xml=f.read()
total=N*2
xml=re.sub(r'<RxPdo[^>]*>.*?</RxPdo>','<RxPdo Fixed="true" Mandatory="true" Sm="2"><Index>#x1600</Index><Name>RxPDO</Name></RxPdo>',xml,flags=re.DOTALL)
xml=re.sub(r'<TxPdo[^>]*>.*?</TxPdo>','<TxPdo Fixed="true" Mandatory="true" Sm="3"><Index>#x1A00</Index><Name>TxPDO</Name></TxPdo>',xml,flags=re.DOTALL)
for i in range(1,N+1):
    xml=xml.replace('</RxPdo>',f'<Entry><Index>#x7000</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>R{i}</Name><DataType>UINT</DataType></Entry>\n</RxPdo>')
    xml=xml.replace('</TxPdo>',f'<Entry><Index>#x6000</Index><SubIndex>{i}</SubIndex><BitLen>16</BitLen><Name>T{i}</Name><DataType>UINT</DataType></Entry>\n</TxPdo>')
xml=xml.replace('DefaultSize="2" StartAddress="#x1400"',f'DefaultSize="{total}" StartAddress="#x1400"')
xml=xml.replace('DefaultSize="2" StartAddress="#x1800"',f'DefaultSize="{total}" StartAddress="#x1800"')
with open(f'{proj}/TRI_SPI_DC.xml','w',encoding='utf-8') as f: f.write(xml)
print(f'{N} UINT16, {total} bytes')
