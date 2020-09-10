/*
 * @lc app=leetcode id=326 lang=javascript
 *
 * [326] Power of Three
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
const isPowerOfThree = function (n) {
  const isPower = Math.log10(n) / Math.log10(3);
  return isPower % 1 === 0;
};
// @lc code=end
