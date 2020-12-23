import fileinput
from copy import deepcopy

lines = [list(filter(lambda x: x != '\n', list(l))) for l in list(fileinput.input(files='11.txt'))]
rows = len(lines)
cols = len(lines[0])

while True:
  changed = False
  new_lines = deepcopy(lines)
  for r in range(rows):
    for c in range(cols):
      not_empty = 0
      for dr in [-1, 0, 1]:
        for dc in [-1, 0 , 1]:
          if not (dr == 0 and dc == 0):
            rr = r + dr
            cc = c + dc
            while 0 <= rr < rows and 0 <= cc < cols and lines[rr][cc] == '.':
              rr = rr + dr
              cc = cc + dc
            if 0 <= rr < rows and 0 <= cc < cols:
              if lines[rr][cc] == '#':
                not_empty += 1
      if lines[r][c] == 'L':
        if not_empty == 0:
          new_lines[r][c] = '#'
          changed = True
      if lines[r][c] == '#' and not_empty >= 5:
        new_lines[r][c] = 'L'
        changed = True
  if not changed:
    break;
  lines = deepcopy(new_lines)

ans = 0
for i in range(rows):
  for j in range(cols):
    if lines[i][j] == '#':
      ans += 1
print('\n'.join([''.join(l) for l in lines]))
print(ans)