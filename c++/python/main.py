print(" > ".join([str(x) for x in [1, 2, 3]]))
# equivalent to
print("1", "2", "3", sep=" > ")

def comp(x):
  return x % 5

print(max(100, 51, 22, key=comp), min(100, 51, 22, key=comp))

def fib(n):
  if n <= 1:
    return n
  return fib(n - 1) + fib(n - 2)

cache = {'0': 0, '1': 1}

def fib_dp(n):
  if str(n) in cache:
    return cache[n]
  cache[n] = fib(n - 1) + fib(n - 2)
  return cache[n]

def force(x, y):
  if x < 0:
    return 0
  x = y(x - 2, y)
  y = lambda x, y: x / 2 + 1
  return y(x, y)
  
print(force(2, force))