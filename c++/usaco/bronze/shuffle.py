import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('shuffle.in', 'r')
sys.stdout = open('shuffle.out', 'w')

def read():
  return [int(x) for x in input().split()]

n = int(input())
a = read()
ids = read() 

start_point = {}
for i in range(1, n + 1):
  start_point[a[i - 1]] = i

cow_start = {}
for i in range(1, n + 1):
  cow_start[start_point[start_point[start_point[i]]]] = ids[i - 1]

for i in range(1, n + 1):
  print(cow_start[i])