import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('backforth.in', 'r')
sys.stdout = open('backforth.out', 'w')

def read():
  return [int(x) for x in input().split()]

possible_answers = set()

def friday(tank1, a, b):
  for i in b:
    possible_answers.add(tank1 + i)

def thursday(tank1, a, b):
  for i in a:
    new_a = a.copy()
    new_b = b.copy()
    new_a.remove(i)
    new_b.append(i)
    friday(tank1 - i, a, b)

def wednesday(tank1, a, b):
  for i in b:
    new_a = a.copy()
    new_b = b.copy()
    new_a.append(i)
    new_b.remove(i)
    thursday(tank1 + i, new_a, new_b)

def tuesday(tank1, a, b):
  for i in a:
    new_a = a.copy()
    new_b = b.copy()
    new_a.remove(i)
    new_b.append(i)
    wednesday(tank1 - i, new_a, new_b)

tuesday(1000, read(), read())

print(len(possible_answers))