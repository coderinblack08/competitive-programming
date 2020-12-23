import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('breedflip.in', 'r')
sys.stdout = open('breedflip.out', 'w')

n = int(input())
a = str(input())
b = str(input())

ans = 0
prev = False
for i in range(n):
  if a[i] != b[i] and not prev:
    prev = True
    ans += 1
  elif a[i] == b[i]:
    prev = False

print(ans)