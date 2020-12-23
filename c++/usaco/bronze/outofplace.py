import sys
# sys.stdin = open('input.txt', 'r')
sys.stdin = open('outofplace.in', 'r')
sys.stdout = open('outofplace.out', 'w')

n = int(input())
line = [int(input()) for x in range(n)]

sorted_line = sorted(line)
ans = -1
for i in range(n):
    if sorted_line[i] != line[i]:
        ans += 1
ans = max(0, ans)
print(ans)
