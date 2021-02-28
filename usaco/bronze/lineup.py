import sys
import itertools

sys.stdin = open('input.txt', 'r')
# sys.stdin = open('lineup.in', 'r')
# sys.stdout = open('lineup.out', 'w')

n = int(input())
constraints = {}
for i in range(n):
  line = input().split()
  constraints[line[0]] = line[-1]

for order in itertools.permutations(['Bessie', 'Buttercup', 'Belinda', 'Beatrice', 'Bella', 'Blue', 'Betsy', 'Sue'], 8):
  works = True
  for a, b in constraints.items():
    a_pos = order.index(a)
    b_pos = order.index(b)
    if abs(a_pos - b_pos) > 1:
      works = False
      break
  if works:
    print(order)