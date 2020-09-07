/*
 * @lc app=leetcode id=101 lang=javascript
 *
 * [101] Symmetric Tree
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

const isSymmetricHelper = (left, right) => {
  if (!left || !right) return left === right;
  if (left.val !== right.val) return false;
  return (
    isSymmetricHelper(left.left, right.right) &&
    isSymmetricHelper(left.right, right.left)
  );
};

const isSymmetric = function (root) {
  return !root || isSymmetricHelper(root.left, root.right);
};
// @lc code=end
