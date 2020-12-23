def works(x):
  while x > 1:
    if (x % 2 == 0):
      x /= 2
    elif x % 5 == 0:
      x /= 5
    else:
      return False
  return True
ans = 0
for i in range(900):
  if works(i):
    ans+=1
print(ans)