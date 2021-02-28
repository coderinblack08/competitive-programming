import sys

sys.stdin = open('input.txt', 'r')
# sys.stdin = open('revegetate.in', 'r')
# sys.stdout = open('revegetate.out', 'w')

n, m = map(int, input().split())
pastures = []

for i in range(m):
  a, b = map(int, input().split())
  if a > b:
    pastures.append((b, a))
  else:
    pastures.append((a, b))

ans = ''
colors = [None] * m
for i in range(1, n + 1):
  color = None
  for g in range(1, 5):
    ok = True
    for j in range(m):
      if pastures[j][1] == i and colors[pastures[j][0]] == g:
        ok = False
    if ok:
      color = g
      break
  colors[i] = color
  ans += str(color)

print(int(ans))
