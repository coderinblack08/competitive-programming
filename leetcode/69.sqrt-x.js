/*
 * @lc app=leetcode id=69 lang=javascript
 *
 * [69] Sqrt(x)
 */

// @lc code=start
/**
 * @param {number} x
 * @return {number}
 */
const mySqrt = function (x) {
  if (!x) return 0;
  let left = 1,
    right = Number.MAX_SAFE_INTEGER;
  while (true) {
    const middle = left + Math.floor((right - left) / 2);
    if (middle > Math.floor(x / middle)) {
      right = middle - 1;
    } else {
      if (middle + 1 > Math.floor(x / (middle + 1))) {
        return middle;
      }
      left = middle + 1;
    }
  }
};
// @lc code=end
