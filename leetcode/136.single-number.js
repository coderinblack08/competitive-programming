/*
 * @lc app=leetcode id=136 lang=javascript
 *
 * [136] Single Number
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
const singleNumber = function (nums) {
  let answer = 0;
  nums.forEach((num) => (answer ^= num));
  return answer;
};
// @lc code=end
