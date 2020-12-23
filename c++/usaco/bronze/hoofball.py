import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('hoofball.in', 'r')
sys.stdout = open('hoofball.out', 'w')

n = int(input())
cows = [int(x) for x in input().split()]
cows = sorted(cows)

direction = [None] * n
direction[0] = 'right'
direction[n - 1] = 'left'

for i in range(1, n - 1):
  if cows[i] - cows[i - 1] <= cows[i + 1] - cows[i]:
    direction[i] = 'left'
  else:
    direction[i] = 'right'

passed = [0] * n
for i in range(n):
  if direction[i] == 'left':
    passed[i - 1] += 1
  else:
    passed[i + 1] += 1

balls = 0
for i in range(n):
  if passed[i] == 0:
    balls += 1
  if passed[i] == 1 and (i < n - 1 and passed[i + 1] == 1) and direction[i] == 'right' and direction[i + 1] == 'left':
    balls += 1

print(balls)