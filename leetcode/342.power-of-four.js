/*
 * @lc app=leetcode id=342 lang=javascript
 *
 * [342] Power of Four
 */

// @lc code=start
/**
 * @param {number} num
 * @return {boolean}
 */
const isPowerOfFour = function (num) {
  const isPower = Math.log10(num) / Math.log10(4);
  return isPower % 1 === 0;
};
// @lc code=end
