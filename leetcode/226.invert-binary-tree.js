/*
 * @lc app=leetcode id=226 lang=javascript
 *
 * [226] Invert Binary Tree
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
 * @return {TreeNode}
 */
const invertTree = function (root) {
  if (!root) return null;
  let left = invertTree(root.left),
    right = invertTree(root.right);
  root.left = right;
  root.right = left;
  return root;
};
// @lc code=end
