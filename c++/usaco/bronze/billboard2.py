import sys

# sys.stdin = open('billboard.in', 'r')
# sys.stdout = open('billboard.out', 'w')

lawn_mower = [int(i) for i in input().split()]
cow_feed = [int(i) for i in input().split()]

def point_in(x, y):
  return x >= cow_feed[0] and x <= cow_feed[2] and y >= cow_feed[1] and y <= cow_feed[3]

points = 0
if point_in(lawn_mower[0], lawn_mower[1]):
  points += 1
if point_in(lawn_mower[0], lawn_mower[3]):
  points += 1
if point_in(lawn_mower[2], lawn_mower[1]):
  points += 1
if point_in(lawn_mower[2], lawn_mower[3]):
  points += 1

if points < 2:
  print((lawn_mower[3] - lawn_mower[1]) * (lawn_mower[2] - lawn_mower[0]))
elif points == 4:
  print(0)
else:
  interception = (min())
  print((lawn_mower[3] - lawn_mower[1]) * (lawn_mower[2] - lawn_mower[0]) - interception)