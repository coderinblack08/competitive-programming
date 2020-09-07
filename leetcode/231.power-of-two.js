/*
 * @lc app=leetcode id=231 lang=javascript
 *
 * [231] Power of Two
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
const isPowerOfTwo = function (n) {
  return n > 0 && !(n & (n - 1));
};
// @lc code=end
