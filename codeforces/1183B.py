import sys
# sys.stdin = open('input.txt', 'r')

q = int(input())

for i in range(q):
  n, k = map(int, input().split())
  a = [int(x) for x in input().split()]
  works = True
  ans = min(a) + k
  for j in a:
    if abs(ans - j) > k:
      works = False
      break
  if works:
    print(ans)
  else:
    print(-1)