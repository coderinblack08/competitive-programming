import fileinput
lines = [l.strip() for l in list(fileinput.input(files='18.txt'))]

p1 = 0
for l in lines:
  l = l.replace('(', '( ').replace(')', ' )')
  words = l.split()

print(p1)