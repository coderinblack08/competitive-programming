/*
 * @lc app=leetcode id=409 lang=javascript
 *
 * [409] Longest Palindrome
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
const longestPalindrome = (s) => {
  const set = new Set();
  let count = 0;
  [...s].forEach((char) => {
    if (set.has(char)) {
      set.delete(char);
      count++;
    } else {
      set.add(char);
    }
  });
  if (set.size) return count * 2 + 1;
  return count * 2;
};
// @lc code=end
