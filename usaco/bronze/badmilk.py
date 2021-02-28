import sys

sys.stdin = open('input.txt', 'r')
# sys.stdin = open('badmilk.in', 'r')
# sys.stdout = open('badmilk.out', 'w')

def read():
  return [int(x) for x in input().split()] 

n, m, d, s = read() # n = friends, m = types of milks (1 bad), d = line count, s = next sick lines

timeline = []
for i in range(d):
  p, m, t = read()
  timeline.append((p, m, t))

timeline = sorted(timeline, key=lambda x: x[2])

sick = []
for i in range(s):
  p, t = read()
  sick.append((p, t))

def drank_before(person, milk_type, time):
  for i in range(d):
    if person == timeline[i][0] and milk_type == timeline[i][1] and timeline[i][2] < time:
      return True
  return False

def milk_bad(milk_type):
  for i in range(s):
    if not drank_before(sick[i][0], milk_type, sick[i][1]):
      return False
  return True

def num_drank(milk_type):
  did_drink = [False] * 51
  for i in range(d):
    if timeline[i][1] == milk_type:
      did_drink[timeline[i][0]] = True
  c = 0
  for i in did_drink:
    if i:
      c += 1
  return c

max_sick = 0
for i in range(m):
  if milk_bad(i):
    max_sick = max(max_sick, num_drank(i))
print(max_sick)