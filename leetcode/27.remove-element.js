/*
 * @lc app=leetcode id=27 lang=javascript
 *
 * [27] Remove Element
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
const removeElement = function (nums, val) {
  let index = 0;
  nums.forEach((num) => {
    if (num !== val) {
      nums[index++] = num;
    }
  });
  return index;
};
// @lc code=end
