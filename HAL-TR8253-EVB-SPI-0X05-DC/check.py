import re
p = r'd:/YPC/Desktop/Keil5 Project/HAL-TR8253-EVB-SPI-0X05-DC/SSC/SSC-DeviceObjects.h'
with open(p, 'rb') as f:
    c = f.read().decode('latin-1')

# Trailing numbers after closing brace
for m in re.finditer(r'\}(\d+)\r\n', c):
    line = c[:m.start()].count('\n') + 1
    print('Line %d: trailing number after }' % line)

# SI128
if 'SI128;}' in c:
    print('SI128;} issue: YES')
if 'SI128;\r\n}' in c:
    print('SI128;\\n} OK')

# Missing #endif
missing = len(re.findall(r'=\{128,[^}]+?\}\r\n\t;', c))
has = len(re.findall(r'=\{128,[^}]+?\}\r\n#endif\r\n\t;', c))
print('Missing #endif: %d, Has #endif: %d' % (missing, has))

# Nested comment
nested = len(re.findall(r'/\*.*?/\*', c, re.DOTALL))
print('Nested comment patterns: %d' % nested)

# Preprocessor
ifs = c.count('#if ') + c.count('#ifdef ') + c.count('#ifndef ')
endifs = c.count('#endif')
print('Preprocessor: opens=%d closes=%d diff=%d' % (ifs, endifs, ifs-endifs))

# Key structs
for s in ['TOBJ6000','TOBJ7000','TOBJ1600','TOBJ1A00','ApplicationObjDic',
          'asEntryDesc0x6000','asEntryDesc0x7000','asEntryDesc0x1600','asEntryDesc0x1A00']:
    print('%s: %s' % (s, 'OK' if s in c else 'MISSING'))
print('Done')
