/*
 * @lc app=leetcode id=268 lang=javascript
 *
 * [268] Missing Number
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
const missingNumber = function (nums) {
  const sum = nums.reduce((acc, num) => (acc += num));
  return (nums.length * (nums.length + 1)) / 2 - sum;
};
// @lc code=end
