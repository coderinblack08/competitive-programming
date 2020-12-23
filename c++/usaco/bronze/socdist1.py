import sys

sys.stdin = open('input.txt', 'r')
# sys.stdin = open('socdist1.in', 'r')
# sys.stdout = open('socdist1.out', 'w')

n = int(input())
stalls = input()

def largest_gap(s):
  cur = -1
  gap = 0
  start = 0
  for i in range(n):
    if s[i] == '1':
      if cur != -1 and i - cur > gap:
        biggest_gap = i - cur
        start = cur
      cur = i
  return (gap, start)

def smallest_gap(s):
  cur = -1
  gap = float('inf')
  for i in range(n):
    if s[i] == '1':
      if cur != -1 and i - cur < gap:
        smallest_gap = i - cur
      cur = i
  return gap

def try_in_largest_gap(s):
  gap_start, gap = largest_gap(s)
  copy_stalls = stalls
  if gap >= 2:
    copy_stalls[start + gap // 2] = '1'
    return smallest_gap()
  return -1

start, gap = largest_gap(stalls)
ans = 0
if gap >= 3:
  temp = stalls
  temp[start + gap / 3] = '1'
  temp[start + gap * 2 / 3] = '1'
  ans = max(smallest_gap(temp), ans)

if stalls[0] == '0' and stalls[-1] == '0':
  temp = stalls
  temp[0] = temp[-1] = '1'
  ans = max(smallest_gap(temp), ans)

if s[0] == '0':
  temp = stalls
  temp[0] = '1'
  ans = max(ans, try_in_largest_gap(temp))

if s[-1] == '0':
  temp = stalls
  temp[-1] = '1'
  ans = max(ans, try_in_largest_gap(temp))

if largest_gap >= 2:
  temp = stalls
  temp[start + gap // 2] == '1'
  ans = max(ans, try_in_largest_gap(temp))

print(ans)