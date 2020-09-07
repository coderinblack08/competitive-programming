/*
 * @lc app=leetcode id=292 lang=javascript
 *
 * [292] Nim Game
 */

// @lc code=start
/**
 * @param {number} n
 * @return {boolean}
 */
const canWinNim = function (n) {
  return n % 4 !== 0;
};
// @lc code=end
