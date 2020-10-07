/*
 * @lc app=leetcode id=414 lang=javascript
 *
 * [414] Third Maximum Number
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number}
 */
const thirdMax = (nums) => {
  let [max1, max2, max3] = [-Infinity, -Infinity, -Infinity];
  nums.forEach((num) => {
    if (![max1, max2, max3].includes(num)) {
      if (num > max1) {
        max3 = max2;
        max2 = max1;
        max1 = num;
      } else if (num > max2) {
        max3 = max2;
        max2 = num;
      } else if (num > max3) {
        max3 = num;
      }
    }
  });
  return max3 !== -Infinity ? max3 : max1;
};
// @lc code=end
