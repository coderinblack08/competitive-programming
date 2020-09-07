/*
 * @lc app=leetcode id=190 lang=javascript
 *
 * [190] Reverse Bits
 */

// @lc code=start
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
const reverseBits = function (n) {
  return n.toString().split``.reverse().join``;
};
// @lc code=end
