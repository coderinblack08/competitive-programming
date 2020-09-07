/*
 * @lc app=leetcode id=258 lang=javascript
 *
 * [258] Add Digits
 */

// @lc code=start
/**
 * @param {number} num
 * @return {number}
 */
const addDigits = function (num) {
  if (num < 10) return num;
  let sum = 0;
  while (num) {
    sum += num % 10;
    num = Math.floor(num / 10);
  }
  return addDigits(sum);
};
// @lc code=end
