/*
 * @lc app=leetcode id=232 lang=javascript
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
/**
 * Initialize your data structure here.
 */
class MyQueue {
  stack = [];
  push = (value) => {
    this.stack.push(value);
  };
  pop = () => this.stack.shift();
  peek = () => this.stack[0];
  empty = () => !this.stack.length;
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
// @lc code=end
