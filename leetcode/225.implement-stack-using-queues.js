/*
 * @lc app=leetcode id=225 lang=javascript
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
/**
 * Initialize your data structure here.
 */
class MyStack {
  stack = [];
  push = (value) => this.stack.push(value);
  pop = () => this.stack.pop();
  top = () => this.stack[this.stack.length - 1];
  empty = () => this.stack.length === 0;
}
/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
// @lc code=end
