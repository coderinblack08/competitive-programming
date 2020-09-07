/*
 * @lc app=leetcode id=496 lang=javascript
 *
 * [496] Next Greater Element I
 */

// @lc code=start
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
const nextGreaterElement = function (nums1, nums2) {
  const nextGreatest = {};
  const stack = [];
  nums2.forEach((num) => {
    while (stack.length && stack[stack.length - 1] < num) {
      nextGreatest[stack.pop()] = num;
    }
    stack.push(num);
  });
  nums1.forEach((num, i) => {
    nums1[i] = nextGreatest[num] ? nextGreatest[num] : -1;
  });
  return nums1;
};
// @lc code=end
