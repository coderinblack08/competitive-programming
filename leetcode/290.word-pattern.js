/*
 * @lc app=leetcode id=290 lang=javascript
 *
 * [290] Word Pattern
 */

// @lc code=start
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
const wordPattern = function (pattern, str) {
  const map = {};
  const array = str.split(' ');
  const patternArray = pattern.split('');
  if (array.length !== pattern.length) return false;
  if ([...new Set(patternArray)].length !== [...new Set(array)].length)
    return false;
  for (let i = 0; i < array.length; i++) {
    if (map.hasOwnProperty(pattern[i])) {
      if (map[pattern[i]] !== array[i]) {
        return false;
      }
    } else {
      map[pattern[i]] = array[i];
    }
  }
  return true;
};
// @lc code=end
