import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('cowsignal.in', 'r')
sys.stdout = open('cowsignal.out', 'w')

m, n, k = [int(x) for x in input().split()]
lines = [input() for _ in range(m)]

ans = []

for l in lines:
  for i in range(k):
    ans.append(''.join([x * k for x in list(l)]))
    
print('\n'.join(ans))