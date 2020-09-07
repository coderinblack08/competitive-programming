/*
 * @lc app=leetcode id=234 lang=javascript
 *
 * [234] Palindrome Linked List
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
 * @return {boolean}
 */
const reverseList = (node) => {
  let prev = null;
  while (node) {
    const next = node.next;
    node.next = prev;
    prev = node;
    node = next;
  }
  return prev;
};

const isPalindrome = function (head) {
  let fast = head,
    slow = head;
  while (fast && fast.next) {
    fast = fast.next.next;
    slow = slow.next;
  }
  if (fast) {
    slow = slow.next;
  }
  slow = reverseList(slow);
  fast = head;
  while (slow) {
    if (fast.val !== slow.val) {
      return false;
    }
    fast = fast.next;
    slow = slow.next;
  }
  return true;
};
// @lc code=end
