import fileinput
import re

lines = [l.strip() for l in list(fileinput.input(files='12.txt'))]
direction = 1
x = 0
y = 0
for line in lines:
  cmd = line[0]
  dist = int(line[1:])
  if cmd == 'N':
    y += dist
  elif cmd == 'E':
    x += dist
  elif cmd == 'S':
    y -= dist
  elif cmd == 'W':
    x -= dist
  elif cmd == 'L':
    direction = (direction + 3 * (dist // 90)) % 4
  elif cmd == 'R':
    direction = (direction + 1 * (dist // 90)) % 4
  elif cmd == 'F':
    x += [0, 1, 0, -1][direction] * dist
    y += [1, 0, -1, 0][direction] * dist
print(abs(x) + abs(y))