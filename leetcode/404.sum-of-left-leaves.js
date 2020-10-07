/*
 * @lc app=leetcode id=404 lang=javascript
 *
 * [404] Sum of Left Leaves
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
 * @return {number}
 */
const sumOfLeftLeaves = function (root) {
  if (!root) return 0;
  let answer = 0;
  if (root.left) {
    if (!root.left.left && !root.left.right) {
      answer += root.left.val;
    } else {
      answer += sumOfLeftLeaves(root.left);
    }
  }
  answer += sumOfLeftLeaves(root.right);
  return answer;
};
// @lc code=end
