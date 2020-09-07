/*
 * @lc app=leetcode id=38 lang=javascript
 *
 * [38] Count and Say
 */

// @lc code=start
/**
 * @param {number} n
 * @return {string}
 */
const countAndSay = function (n) {
  if (!n) return '';
  let result = '';
  while (n--) {
    let current = '';
    for (let i = 0; i < result.length; i++) {
      while (i + 1 < result.length && result[i] === result[i + 1]) {
        let count = 1;
        count++;
        i++;
      }
      current += count.toString() + result[i];
    }
    result = current;
  }
  return result;
};
// @lc code=end
