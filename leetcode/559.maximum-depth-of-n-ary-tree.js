/*
 * @lc app=leetcode id=559 lang=javascript
 *
 * [559] Maximum Depth of N-ary Tree
 */

// @lc code=start
/**
 * // Definition for a Node.
 * function Node(val,children) {
 *    this.val = val;
 *    this.children = children;
 * };
 */

/**
 * @param {Node} root
 * @return {number}
 */
const maxDepth = function (root) {
  if (!root) return 0;
  let depth = 0;
  const queue = [root];
  while (queue.length) {
    const size = queue.length;
    for (let j = 0; j < size; j++) {
      const current = queue.shift();
      queue.push(...current.children);
    }
    depth++;
  }
  return depth;
};
// @lc code=end
