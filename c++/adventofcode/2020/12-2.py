import fileinput
import re

lines = [l.strip() for l in list(fileinput.input(files='12.txt'))]
direction = 1
x = 0
y = 0
wx = 1
wy = 10
for line in lines:
  cmd = line[0]
  dist = int(line[1:])
  if cmd == 'N':
    wy += dist
  elif cmd == 'E':
    wx += dist
  elif cmd == 'S':
    wy -= dist
  elif cmd == 'W':
    wx -= dist
  elif cmd == 'L':
    for _ in range(dist // 90):
      wx, wy = -wy, wx
  elif cmd == 'R':
    for _ in range(dist // 90):
      wx, wy = wy, -wx
  elif cmd == 'F':
    x += dist * (wx)
    y += dist * (wy)
print(abs(x) + abs(y))