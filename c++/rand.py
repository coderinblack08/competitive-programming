import random

n = random.randint(3, 6)
print(n)
for i in range(n):
  n = random.randint(1, 2)
  if n == 1:
    print('N', random.randint(1, 10), random.randint(1, 10))
  else:
    print('E', random.randint(1, 10), random.randint(1, 10))