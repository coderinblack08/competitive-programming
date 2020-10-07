/*
 * @lc app=leetcode id=389 lang=javascript
 *
 * [389] Find the Difference
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
const findTheDifference = function (s, t) {
  return String.fromCharCode(
    [...(s + t)].map((c) => c.charCodeAt()).reduce((a, c) => (a ^= c), 0)
  );
};
// @lc code=end
