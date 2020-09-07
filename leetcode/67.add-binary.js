/*
 * @lc app=leetcode id=67 lang=javascript
 *
 * [67] Add Binary
 */

// @lc code=start
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
const addBinary = function (a, b) {
  let carry = 0,
    answer = new String();
  let i = a.length - 1,
    j = b.length - 1;
  while (i >= 0 || j >= 0) {
    let sum = carry;
    if (i >= 0) {
      sum += +a[i--];
    }
    if (j >= 0) {
      sum += +b[j--];
    }
    answer = (sum % 2).toString() + answer;
    carry = (sum / 2) | 0;
  }
  if (carry) {
    answer = '1' + answer;
  }
  return answer;
};
// @lc code=end
