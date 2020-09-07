/*
 * @lc app=leetcode id=119 lang=javascript
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
const getRow = function (rowIndex) {
  const row = new Array(rowIndex + 1).fill(0);
  row[0] = 1;
  for (let i = 0; i < rowIndex + 1; i++) {
    for (let j = i; j >= 1; j--) {
      row[j] += row[j - 1];
    }
  }
  return row;
};
// @lc code=end
