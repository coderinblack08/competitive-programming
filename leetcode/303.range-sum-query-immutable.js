/*
 * @lc app=leetcode id=303 lang=javascript
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
  /**
   * @param {number[]} nums
   */
  constructor(nums) {
    this.nums = nums;
    this.sums = new Array(nums.length + 1).fill(0);
    this.nums.forEach((num, i) => {
      this.sums[i + 1] = this.sums[i] + this.nums[i];
    });
  }
  /**
   * @param {number} start
   * @param {number} end
   */
  sumRange = (start, end) => {
    return this.sums[end + 1] - this.sums[start];
  };
}
// @lc code=end
