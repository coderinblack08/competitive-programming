import sys

sys.stdin = open('input.txt', 'r')

n = int(input())
pos = {}
instructions = []

for i in range(n):
  d, x, y = input().split()
  instructions.append(d)
  pos[i] = (int(x), int(y))

def pass_by(a, b):
  dir1 = instructions[a]
  dir2 = instructions[b]
  x1, y1 = pos[a]
  x2, y2 = pos[b]
  if dir1 == 'E' and dir2 == 'N' and abs(x2 - x1) == abs(y2 - y1):
    if x1 < x2 and y1 > y2:
      return None
  if dir1 == 'N' and dir2 == 'E' and abs(x2 - x1) == abs(y2 - y1):
    if x1 > x2 and y1 < y2:
      return None
  if dir1 == 'E' and dir2 == 'E':
    if y1 == y2:
      if x1 > x2:
        return (b, abs(x2 - x1))
      else:
        return (a, abs(x2 - x1))
  if dir1 == 'N' and dir2 == 'N':
    if x1 == x2:
      if y1 > y2:
        return (b, abs(y2 - y1))
      else:
        return (a, abs(y2 - y1))
  if dir1 == 'E' and dir2 == 'N':
    if x2 >= x1 and y2 <= y1:
      dist1 = abs(x2 - x1)
      dist2 = abs(y2 - y1)
      if dist1 < dist2:
        return (b, dist2)
      else:
        return (a, dist1)
  if dir1 == 'N' and dir2 == 'E':
    if x2 <= x1 and y2 >= y1:
      dist1 = abs(y2 - y1)
      dist2 = abs(x2 - x1)
      if dist1 < dist2:
        return (b, dist2)
      else:
        return (a, dist1)
  return None

ans = [float('inf')] * n
for i in range(n - 1, -1, -1):
  for j in range(i - 1, -1, -1):
    if pass_by(i, j) != None:
      cow, ate = pass_by(i, j)
      works = True
      if j == cow:
        if ans[i] < ate:
          works = False
      else:
        if ans[j] < ate:
          works = False
      if cow in ans:
        if works:
          ans[cow] = min(ans[cow], ate)
      else:
        if works:
          ans[cow] = ate

for i in range(n):
  if ans[i] == float('inf'):
    ans[i] = "Infinity"
  print(ans[i])
