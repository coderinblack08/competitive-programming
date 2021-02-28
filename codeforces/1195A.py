import sys
sys.stdin = open('input.txt', 'r')
n, k = map(int, input().split())
 
a = {}
for i in range(n):
  k = int(input())
  if k in a:
    a[k] += 1
  else:
    a[k] = 1

print(a)

ans = 0
count = 0
for a in a.values():
  count += a % 2
  ans += a // 2 * 2

print(ans + (count + 1) // 2)