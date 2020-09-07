/*
 * @lc app=leetcode id=169 lang=javascript
 *
 * [169] Majority Element
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
const majorityElement = function (nums) {
  const size = nums.length / 2;
  const map = {};
  for (let i = 0; i < nums.length; i++) {
    if (map.hasOwnProperty(nums[i])) {
      map[nums[i]]++;
      if (map[nums[i]] >= size) {
        return nums[i];
      }
    } else {
      map[nums[i]] = 1;
    }
  }
  return nums[0];
};
// @lc code=end
