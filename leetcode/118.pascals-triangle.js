/*
 * @lc app=leetcode id=118 lang=javascript
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
/**
 * @param {number} numRows
 * @return {number[][]}
 */
const generate = function (numRows) {
  if (!numRows) return [];
  const result = [[1]];
  for (let i = 0; i < numRows - 1; i++) {
    let row = [];
    for (let j = 0; j < result[i].length - 1; j++) {
      row.push(result[i][j] + result[i][j + 1]);
    }
    row = [1, ...row, 1];
    result.push(row);
  }
  return result;
};
// @lc code=end
