/*
 * @lc app=leetcode id=172 lang=javascript
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
const trailingZeroes = function (n) {
  if (n < 5) return 0;
  let answer = 0;
  while (n > 0) {
    n = Math.floor(n / 5);
    answer += n;
  }
  return answer;
};
// @lc code=end
