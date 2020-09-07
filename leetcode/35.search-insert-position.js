/*
 * @lc app=leetcode id=35 lang=javascript
 *
 * [35] Search Insert Position
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
const searchInsert = function (nums, target) {
  let low = 0,
    high = nums.length - 1;
  while (low <= high) {
    const middle = low + Math.floor((high - low) / 2);
    if (nums[middle] === target) {
      return middle;
    } else if (nums[middle] > target) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }
  return low;
};
// @lc code=end
