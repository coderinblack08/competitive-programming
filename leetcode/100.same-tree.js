/*
 * @lc app=leetcode id=100 lang=javascript
 *
 * [100] Same Tree
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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
const isSameTree = function (p, q) {
  if (!p || !q) return p === q;
  if (p.val === q.val)
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
  return false;
};
// @lc code=end
