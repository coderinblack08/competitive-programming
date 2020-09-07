/*
 * @lc app=leetcode id=203 lang=javascript
 *
 * [203] Remove Linked List Elements
 */

// @lc code=start
function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}
/**
 * @param {ListNode} head
 * @param {number} val
 * @return {ListNode}
 */
const removeElements = function (head, val) {
  if (!head) return null;
  head.next = removeElements(head.next, val);
  return head.val === val ? head.next : head;
};
// @lc code=end
