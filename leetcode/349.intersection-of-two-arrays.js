/*
 * @lc app=leetcode id=349 lang=javascript
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
const intersection = function (nums1, nums2) {
  const intersection = new Set();
  const set = new Set();
  nums1.forEach((num) => {
    set.add(num);
  });
  nums2.forEach((num) => {
    if (set.has(num)) {
      intersection.add(num);
    }
  });
  return [...intersection];
};
// @lc code=end
