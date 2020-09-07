/*
 * @lc app=leetcode id=112 lang=javascript
 *
 * [112] Path Sum
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

/**
 * @param {TreeNode} root
 * @param {number} sum
 * @return {boolean}
 */
const hasPathSum = function (root, sum) {
  if (!root) return false;
  if (!root.left && !root.right && sum - root.val === 0) return true;
  return (
    hasPathSum(root.left, sum - root.val) ||
    hasPathSum(root.right, sum - root.val)
  );
};
// @lc code=end
