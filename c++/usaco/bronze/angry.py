import sys
# sys.stdin = open('input.txt', 'r')
sys.stdin = open('angry.in', 'r')
sys.stdout = open('angry.out', 'w')

n = int(input())
bales = [int(input()) for _ in range(n)]

bales = sorted(bales)

def find_explosion(idx, left):
  last_explosion = idx
  radius = 1
  while last_explosion > 0 and last_explosion < n - 1:
    direction = -1 if left else 1
    next_idx = last_explosion
    while next_idx + direction >= 0 and next_idx + direction < n and abs(bales[next_idx + direction] - bales[last_explosion]) <= radius:
      next_idx += direction
    if next_idx == last_explosion:
      break
    last_explosion = next_idx
    radius += 1
  return last_explosion

ans = 1
for i in range(n):
  leftmost = find_explosion(i, True)
  rightmost = find_explosion(i, False)
  exploded = rightmost - leftmost + 1
  ans = max(ans, exploded)
print(ans)
