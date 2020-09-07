/*
 * @lc app=leetcode id=219 lang=javascript
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
const containsNearbyDuplicate = function (nums, k) {
  const map = new Map();
  for (let i = 0; i < nums.length; i++) {
    const current = nums[i];
    if (map.has(current) && i - map.get(current) <= k) {
      return true;
    } else {
      map.set(current, i);
    }
  }
  return false;
};
// @lc code=end
