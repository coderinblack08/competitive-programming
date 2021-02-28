import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('balancing.in', 'r');
sys.stdout = open('balancing.out', 'w')

n, b = [int(x) for x in input().split()]
m = n

grid = [] 
for i in range(n):
  x, y = [int(x) for x in input().split()]
  grid.append((x, y))

for ai in range(n):
  for ci in range(n):
    a = grid[ai][0] - 1
    c = grid[ci][1] - 1
    ne = 0
    es = 0
    sw = 0
    nw = 0
    for x, y in grid:
      if x > a and y > c:
        ne += 1
      if x > a and y < c:
        es += 1
      if x < a and y < c:
        sw += 1
      if x < a and y > c:
        nw += 1
    m = min(m, max(ne, es, sw, nw))

print(m)