/*
 * @lc app=leetcode id=107 lang=javascript
 *
 * [107] Binary Tree Level Order Traversal II
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
 * @return {number[][]}
 */
const levelOrderBottom = function (root) {
  let result = new Array();
  if (!root) {
    return result;
  }
  const queue = [root];
  while (queue.length) {
    const size = queue.length;
    const currentLevel = new Array();
    for (let i = 0; i < size; i++) {
      const current = queue.shift();
      currentLevel.push(current.val);
      if (current.left) queue.push(current.left);
      if (current.right) queue.push(current.right);
    }
    result = [currentLevel, ...result];
  }
  return result;
};
// @lc code=end
