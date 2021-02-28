import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('mixmilk.in', 'r')
sys.stdout = open('mixmilk.out', 'w')
amount = [None] * 3
capcity = [None] * 3

def output():
  for i in range(3):
    print(amount[i])

for i in range(3):
  c, a = map(int, input().split())
  amount[i] = a
  capcity[i] = c

for i in range(100):
  pour_from = i % 3
  pour_to = (i + 1) % 3
  if amount[pour_to] + amount[pour_from] >= capcity[pour_to]:
    amount[pour_from] = (amount[pour_from] + amount[pour_to]) - capcity[pour_to]
    amount[pour_to] = capcity[pour_to]
  else:
    amount[pour_to] = amount[pour_from] + amount[pour_to]
    amount[pour_from] = 0

output()