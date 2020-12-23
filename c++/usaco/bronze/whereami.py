import sys

n = int(input())
road = str(input())

for i in range(1, n + 1):
  seen = set()
for j in range(0, n - i):
    print(seen)
    if road[j: j + i] in seen:
      break
    seen.add(road[j: j + i])
    if j + i == n - 1:
      print(i)
      sys.exit()