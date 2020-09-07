/*
 * @lc app=leetcode id=155 lang=javascript
 *
 * [155] Min Stack
 */

// @lc code=start
/**
 * initialize your data structure here.
 */
class MinStack {
  stack = [];
  min = Infinity;
  push = (value) => {
    if (value <= this.min) {
      this.stack.push(this.min);
      this.min = value;
    }
    this.stack.push(value);
  };
  pop = () => {
    if (this.stack.pop() === this.min) {
      this.min = this.stack.pop();
    }
  };
  top = () => {
    return this.stack[this.stack.length - 1];
  };
  getMin = () => this.min;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
// @lc code=end
