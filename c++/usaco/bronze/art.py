import sys

sys.stdin = open('input.txt', 'r')
# sys.stdin = open('art.in', 'r')
# sys.stdout = open('art.out', 'w')

n = int(input())
art = [list(map(int, list(input()))) for x in range(n)]

rect = {}
for i in range(n):
  for j in range(n):
    if art[i][j] in rect:
      if len(rect[art[i][j]]) == 1:
        rect[art[i][j]].append((j, i))
      else:
        endpoint = rect[art[i][j]][1]
        endpoint = (max(endpoint[0], j), max(endpoint[1], i))
        rect[art[i][j]][1] = endpoint
    else:
      rect[art[i][j]] = [(j, i)]

del rect[0]

overlap_rect = {}

def overlap(a, c, b, d):
  print(a, c, d, b)
  top = c
  bottom = d
  count = 0
  for i in range(a[0][0], a[1][0] + 1):
    for j in range(a[0][1], a[1][1] + 1):
      if art[i][j] == d:
        top = d
        bottom = c
      else:
        count += 1
  print(count)
  print()
  if count == (a[1][0] - a[0][0]) * (a[1][1] - a[0][1]):
    pass 
  elif top in overlap_rect:
    overlap_rect[top].add(bottom) 
  else:
    overlap_rect[top] = set([bottom])

for i, a in rect.items():
  for j, b in rect.items():
    if i != j:
      overlap(a, i, b, j)

print(overlap_rect)