/*
 * @lc app=leetcode id=167 lang=javascript
 *
 * [167] Two Sum II - Input array is sorted
 */

// @lc code=start
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
const twoSum = function (numbers, target) {
  const map = {};
  for (let index = 0; index < numbers.length; index++) {
    const num = numbers[index];
    if (map.hasOwnProperty(target - num)) {
      return [map[target - num] + 1, index + 1];
    }
    map[num] = index;
  }
};
// @lc code=end
