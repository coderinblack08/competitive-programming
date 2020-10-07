/*
 * @lc app=leetcode id=374 lang=javascript
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
const guessNumber = function (n) {
  let low = 1,
    high = n;
  while (low <= high) {
    const middle = low + Math.floor((high - low) / 2);
    if (guess(middle) === -1) {
      high = middle - 1;
    } else if (guess(middle) === 1) {
      low = middle + 1;
    } else {
      return middle;
    }
  }
};
// @lc code=end
