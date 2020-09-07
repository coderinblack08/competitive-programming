/*
 * @lc app=leetcode id=125 lang=javascript
 *
 * [125] Valid Palindrome
 */

// @lc code=start
const isAlphanum = (char) => {
  return /^[A-Za-z0-9]$/i.test(char);
};
/**
 * @param {string} s
 * @return {boolean}
 */
const isPalindrome = function (s) {
  for (let i = 0, j = s.length - 1; i < j; i++, j--) {
    while (!isAlphanum(s[i]) && i < j) {
      i++;
    }
    while (!isAlphanum(s[j]) && i < j) {
      j--;
    }
    if (s[i].toUpperCase() !== s[j].toUpperCase()) {
      return false;
    }
  }
  return true;
};
// @lc code=end
