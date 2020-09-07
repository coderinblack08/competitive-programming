/*
 * @lc app=leetcode id=111 lang=javascript
 *
 * [111] Minimum Depth of Binary Tree
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
function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}
/**
 * @param {TreeNode} root
 * @return {number}
 */
// DFS Approach
// const minDepth = function (root) {
//   if (!root) return 0;
//   const left = minDepth(root.left),
//     right = minDepth(root.right);
//   return !left || !right ? left + right + 1 : Math.min(left, right) + 1;
// };
// BFS Approach (optimal solution)
const minDepth = function (root) {
  if (!root) return 0;
  const queue = [root];
  let level = 1;
  while (queue.length) {
    const size = queue.length;
    for (let i = 0; i < size; i++) {
      const currentNode = queue.shift();
      if (!currentNode.left && !currentNode.right) {
        return level;
      }
      if (currentNode.left) {
        queue.push(currentNode.left);
      }
      if (currentNode.right) {
        queue.push(currentNode.right);
      }
    }
    level++;
  }
  return level;
};
// @lc code=end
