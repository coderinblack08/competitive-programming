import sys

# sys.stdin = open('input.txt', 'r')

line = list(map(int, input().split()))
ans = []
n = len(line)

for i in range(n):
  for j in range(n):
    for k in range(n):
      if i != j and j != k and i != k:
        a = line[i]
        b = line[j]
        c = line[k]
        if a + b in line and b + c in line and c + a in line and a + b + c in line:
          ans = [a, b, c]

print(' '.join(map(str, sorted(ans))))