import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('traffic.in', 'r')
sys.stdout = open('traffic.out', 'w')

n = int(input())
traffic = [input().split() for _ in range(n)]

a = -999999999
b = 999999999
for i in range(n - 1, -1, -1):
  if traffic[i][0] == 'none':
    a = max(a, int(traffic[i][1]))
    b = min(b, int(traffic[i][2]))
  if traffic[i][0] == 'off':
    a += int(traffic[i][1])
    b += int(traffic[i][2])
  if traffic[i][0] == 'on':
    a -= int(traffic[i][2])
    b -= int(traffic[i][1])
    a = max(0, a)
print(a, b)

a = -999999999
b = 999999999
for i in range(n):
  if traffic[i][0] == 'none':
    a = max(a, int(traffic[i][1]))
    b = min(b, int(traffic[i][2]))
  if traffic[i][0] == 'off':
    a -= int(traffic[i][2])
    b -= int(traffic[i][1])
    a = max(0, a)
  if traffic[i][0] == 'on':
    a += int(traffic[i][1])
    b += int(traffic[i][2])
print(a, b)