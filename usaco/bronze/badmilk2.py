import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('badmilk.in', 'r')
sys.stdout = open('badmilk.out', 'w')

def read():
  return [int(x) for x in input().split()]

n, m, d, s = read()
drank = [[float('inf')] * (m + 1) for x in range(n + 1)]
sick = [-1] * (n + 1)
for i in range(d):
  P, M, T = read()
  drank[P][M] = min(drank[P][M], T)

for i in range(s):
  P, T = read()
  sick[P] = T

ans = 0
for i in range(1, m + 1):
  contaminated = True
  for j in range(1, n + 1):
    if sick[j] != -1 and sick[j] <= drank[j][i]:
      contaminated = False
      break
  if contaminated:
    count = 0
    for j in range(1, n + 1):
      if drank[j][i] != float('inf'):
        count += 1
    ans = max(ans, count)

print(ans)