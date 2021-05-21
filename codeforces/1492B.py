for t in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
  look = [0] * n

  look[0] = a[0]
  for i in range(1, n):
    look[i] = max(look[i - 1], a[i])

  j = n
  ans = []
  for i in range(n - 1, -1, -1):
    if look[i] == a[i]:
      ans.extend(a[i:j])
      j = i
  print(*ans)