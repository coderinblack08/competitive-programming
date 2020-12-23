import fileinput
import re

lines = [l.strip() for l in list(fileinput.input(files='14.txt'))]
mask = ''
mem = {}
for line in lines:
  if line.startswith('mask'):
    new_mask = lines.split()[-1]
    mask = new_mask
  elif:
    matches = re.search(r'\w+\[(\d+)\] = (\d+)', line) 
    address = matches.group(1)
    value = int(matches.group(2))
    new_value = 0
    for i, bit in enumerate(reversed(mask)):
      if bit == 'X':
        new_value += value & (2 ** i)
      else:
        new_value += 2 ** i
    mem[int(address)] = value

ans = 0
for v in mem.values():
  ans += v
print(ans)