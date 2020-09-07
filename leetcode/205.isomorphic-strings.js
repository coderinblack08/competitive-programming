/*
 * @lc app=leetcode id=205 lang=javascript
 *
 * [205] Isomorphic Strings
 */

// @lc code=start
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
const isIsomorphic = function (s, t) {
  const map = new Map();
  for (let i = 0; i < s.length; i++) {
    if (map.has(s[i]) && map.get(s[i]) !== t[i]) {
      return false;
    } else {
      map.set(s[i], t[i]);
    }
  }
  return new Set([...map.values()]).size === map.size;
};
// @lc code=end
