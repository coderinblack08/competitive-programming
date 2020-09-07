/*
 * @lc app=leetcode id=108 lang=javascript
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */

const createBST = (nums, left, right) => {
  if (left > right) return null;
  const mid = left + Math.floor((right - left) / 2);
  const current = new TreeNode(nums[mid]);
  current.left = createBST(nums, left, mid - 1);
  current.right = createBST(nums, mid + 1, right);
  return current;
};

/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
const sortedArrayToBST = function (nums) {
  if (!nums || !nums.length) return null;
  return createBST(nums, 0, nums.length - 1);
};
// @lc code=end
