/*
 * @lc app=leetcode id=83 lang=javascript
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
const deleteDuplicates = function (head) {
  let currentNode = head;
  while (head && currentNode.next) {
    if (currentNode.next.val === currentNode.val) {
      currentNode.next = currentNode.next.next;
    } else {
      currentNode = currentNode.next;
    }
  }
  return head;
};
// @lc code=end
