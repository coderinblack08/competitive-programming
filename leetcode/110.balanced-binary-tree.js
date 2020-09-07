/*
 * @lc app=leetcode id=110 lang=javascript
 *
 * [110] Balanced Binary Tree
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
 * @return {boolean}
 */
const depth = (root) => {
  if (!root) return 0;
  return Math.max(depth(root.left), depth(root.right)) + 1;
};

const isBalanced = function (root) {
  if (!root) return true;
  const left = depth(root.left),
    right = depth(root.right);
  return (
    Math.abs(left - right) <= 1 &&
    isBalanced(root.left) &&
    isBalanced(root.right)
  );
};
// @lc code=end
