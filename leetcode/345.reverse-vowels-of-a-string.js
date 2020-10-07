/*
 * @lc app=leetcode id=345 lang=javascript
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
const reverseVowels = function (s) {
  let left = 0,
    right = s.length - 1;
  s = [...s];
  while (left < right) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    if (vowels.has(s[left]) && vowels.has(s[right])) {
      [s[left], s[right]] = [s[right], s[left]];
      left++;
      right--;
    } else if (!vowels.has(s[left])) {
      left++;
    } else {
      right--;
    }
  }
  return s.join``;
};
// @lc code=end
