import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('blist.in', 'r')
sys.stdout = open('blist.out', 'w')

def read():
  return [int(x) for x in input().split()]

n = int(input())
timeline = [0] * 1001

for i in range(n):
  s, t, b = read()
  for j in range(s, t + 1):
    timeline[j] += b

print(max(timeline))