import fileinput
import math
import re

lines = [l.strip() for l in list(fileinput.input(files='13.txt'))]
earliest = int(lines[0])
ids = list(filter(lambda x: x != 'x',lines[1].split(',')))

ans = -1
ans_id = -1
for id in ids:
  id = int(id)
  time = math.ceil(earliest / id) * id
  if ans == -1 or time < ans:
    ans = time 
    ans_id = id
print((ans - earliest) * ans_id)