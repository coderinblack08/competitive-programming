#include <bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int>& nums) {
  int sum = 0, left = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  for (int p = 0; p < nums.size(); p++) {
    if (p != 0) {
      left += nums[p - 1];
    }
    if (sum - left - nums[p] == left) {
      return p;
    }
  }
  return -1;
}

int main() {
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  cout << pivotIndex(nums) << endl;
}