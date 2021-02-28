import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('cowtip.in', 'r')
sys.stdout = open('cowtip.out', 'w')

n = int(input())
grid = [list(input()) for x in range(n)]

# Key to solve the problem, we have to look at the bottom right corner, if it is tipped
# we must then un-tip the whole grid. We can save computation time and only do O(n^2) = 100 operations rather
# than simulating the whole grid like in solution 2.

def cow_tip(x, y):
  for i in range(x + 1):
    for j in range(y + 1):
      if grid[i][j] == '1':
        grid[i][j] = '0'
      else:
        grid[i][j] = '1'

ans = 0
for i in range(n - 1, -1, -1):
  for j in range(n - 1, -1, -1):
    if grid[i][j] == '1':
      cow_tip(i, j)
      ans += 1

print(ans)

# Works but is too slow (simulation)
# def set_left():
#   count = 0
#   for i in range(n):
#     for j in range(n):
#       count += grid[i][j] == '1'
#   return count

# def cow_tip(x, y):
#   for i in range(y + 1):
#     for j in range(x + 1):
#       grid[i][j] = '1' if grid[i][j] == '0' else '0' 

# left = set_left()

# ans = 0
# while left:
#   x = 0
#   y = 0
#   for i in range(n):
#     for j in range(n):
#       if grid[i][j] == '1':
#         x = max(x, j)
#         y = max(y, i)
#   cow_tip(x, y) 
#   left = set_left()
#   ans += 1

# print(ans)
