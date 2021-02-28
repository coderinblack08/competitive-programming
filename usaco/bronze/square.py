import sys

sys.stdin = open('square.in', 'r')
sys.stdout = open('square.out', 'w')

rect1 = [int(i) for i in input().split()]
rect2 = [int(i) for i in input().split()]

ans_x = max(rect1[2], rect2[2]) - min(rect1[0], rect2[0])
ans_y = max(rect1[3], rect2[3]) - min(rect1[1], rect2[1])

print(max(ans_x, ans_y) ** 2)