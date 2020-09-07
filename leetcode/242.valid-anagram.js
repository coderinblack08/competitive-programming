/*
 * @lc app=leetcode id=242 lang=javascript
 *
 * [242] Valid Anagram
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isAnagram = function (s, t) {
  s = s.split``;
  t = t.split``;
  s.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));
  t.sort((a, b) => a.charCodeAt(0) - b.charCodeAt(0));
  if (s.join`` === t.join``) return true;
  return false;
};
// @lc code=end
