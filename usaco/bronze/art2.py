import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('art.in', 'r')
sys.stdout = open('art.out', 'w')

n = int(input())
grid = [list(map(int, list(input()))) for x in range(n)]

good = [True] * 10
for i in range(1, 10):
  min_x = min_y = n + 1
  max_x = max_y = -1
  for x in range(n):
    for y in range(n):
      if grid[x][y] == i:
        min_x = min(min_x, x)
        min_y = min(min_y, y)
        max_x = max(max_x, x)
        max_y = max(max_y, y)
  if max_x == -1:
    good[i] = False
  for x in range(min_x, max_x + 1):
    for y in range(min_y, max_y + 1):
      if grid[x][y] != i:
        good[grid[x][y]] = False

ans = 0
for i in range(len(good)):
  if i != 0:
    ans += 1 if good[i] else 0

print(ans)