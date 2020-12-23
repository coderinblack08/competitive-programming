import sys

sys.stdin = open('input.txt', 'r')

n = int(input())
flowers = list(map(int, input().split()))

ans = n
for i in range(n):
  for j in range(i + 1, n):
    count = 0
    for k in range(i, j + 1):
      count += flowers[k]
    if count / (j - i + 1) in flowers[i:j]:
      ans += 1
    print(count, i, j, flowers[i:j])

print(ans)