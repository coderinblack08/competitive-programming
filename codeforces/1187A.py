import sys

# sys.stdin = open('input.txt', 'r')

t = int(input())
for i in range(t):
  n, s, t = map(int, input().split())
  print(max(n - s, n - t) + 1)