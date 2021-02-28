import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('guess.in', 'r')
sys.stdout = open('guess.out', 'w')

n = int(input())
animals = {}
for i in range(n):
  line = input().split()
  type, _ = line[0:2]
  chars = line[2:]
  animals[i] = chars
import sys

def common(i, j):
  count = 0
  c1 = animals[i]
  c2 = animals[j]
  for a in c1:
    for b in c2:
      if a == b:
        count += 1
  return count

largest = 0
for i in range(n):
  for j in range(i + 1, n):
    largest = max(largest, common(i, j))

print(largest + 1)