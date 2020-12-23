import sys

# sys.stdin = open('input.txt', 'r')
sys.stdin = open('censor.in', 'r')
sys.stdout = open('censor.out', 'w')

s = str(input())
t = str(input())

r = ''
for i in range(len(s)):
  r += s[i]
  if len(r) > len(t) and r[len(r) - len(t):] == t:
    r = r[:len(r) - len(t)]
print(r)