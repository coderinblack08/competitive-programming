/*
 * @lc app=leetcode id=263 lang=javascript
 *
 * [263] Ugly Number
 */

// @lc code=start
/**
 * @param {number} num
 * @return {boolean}
 */
const isUgly = function (num) {
  for (const i of [2, 3, 5]) {
    while (num && !(num % i)) {
      num /= i;
    }
  }
  return num === 1;
};
// @lc code=end
