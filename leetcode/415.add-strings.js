/*
 * @lc app=leetcode id=415 lang=javascript
 *
 * [415] Add Strings
 */

// @lc code=start
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
const addStrings = function (num1, num2) {
  let result = new String();
  let carry = 0;
  for (
    let i = num1.length - 1, j = num2.length - 1;
    i >= 0 || j >= 0 || carry;
    i--, j--
  ) {
    const x = i < 0 ? 0 : parseInt(num1[i]);
    const y = j < 0 ? 0 : parseInt(num2[j]);
    result = `${(x + y + carry) % 10}${result}`;
    carry = Math.floor((x + y + carry) / 10);
  }
  return result;
};
// @lc code=end
