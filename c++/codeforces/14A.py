import sys
sys.stdin = open('input.txt', 'r')

n, m = map(int, input().split())
sheet = [list(input()) for x in range(n)]

top_left = None
bottom_right = None

for i in range(n):
  for j in range(m):
    if top_left == None and sheet[i][j] == '*':
      top_left = (i, j)
    elif sheet[i][j] == '*':
      bottom_right = (i, j)
print(top_left, bottom_right)
section = sheet[top_left[0]:bottom_right[0] + 1][top_left[1]:bottom_right[1] + 1]
section = '\n'.join([''.join(x) for x in section])
print(section)
