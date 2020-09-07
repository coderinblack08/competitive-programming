/*
 * @lc app=leetcode id=28 lang=javascript
 *
 * [28] Implement strStr()
 */

// @lc code=start
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
const strStr = function (haystack, needle) {
  if (!needle.length) {
    return 0;
  } else if (!haystack.length) {
    return -1;
  }
  for (let i = 0; i < haystack.length; i++) {
    if (i + needle.length > haystack.length) {
      break;
    }
    for (let j = 0; j < needle.length; j++) {
      if (haystack[i + j] !== needle[j]) {
        break;
      }
      if (j === needle.length - 1) {
        return i;
      }
    }
  }
  return -1;
};
// @lc code=end
