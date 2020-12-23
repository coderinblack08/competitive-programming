from bisect import bisect_left
input = [1, 2, 5, 6, 7]

# 1, 2, 5, 6, 7
# ?, ?, 5, ?, ?

def binary_search(arr, target):
  left = 0
  right = len(arr) - 1
  while left <= right:
    mid = left + (right - left) // 2
    if arr[mid] == target:
      return mid
    elif arr[mid] < target:
      left = mid + 1
    else:
      right = mid - 1
  return -1

print(binary_search(input, 7))
print(bisect_left(input, 7, 0, len(input)))
