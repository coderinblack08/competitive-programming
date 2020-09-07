/*
 * @lc app=leetcode id=557 lang=javascript
 *
 * [557] Reverse Words in a String III
 */

// @lc code=start
/**
 * @param {string} s
 * @return {string}
 */
const reverseWords = function (s) {
  s = s.split` `;
  s.forEach((character, index) => {
    s[index] = character.split``.reverse().join``;
  });
  return s.join` `;
};
// @lc code=end
