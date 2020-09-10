/*
 * @lc app=leetcode id=881 lang=javascript
 *
 * [881] Boats to Save People
 */

// @lc code=start
/**
 * @param {number[]} people
 * @param {number} limit
 * @return {number}
 */
const numRescueBoats = function (people, limit) {
  people.sort((a, b) => a - b);
  let boats = 0,
    left = 0,
    right = people.length - 1;
  while (left <= right) {
    if (people[left] + people[right] <= limit) {
      left++;
      right--;
    } else {
      right--;
    }
    boats++;
  }
  return boats;
};
// @lc code=end
