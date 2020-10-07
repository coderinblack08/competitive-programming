/*
 * @lc app=leetcode id=387 lang=javascript
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
const firstUniqChar = function (s) {
  const map = {};
  [...s].forEach((letter) => {
    if (map.hasOwnProperty(letter)) {
      map[letter]++;
    } else {
      map[letter] = 1;
    }
  });
  console.log(map);
  for (let i = 0; i < s.length; i++) {
    if (map[s[i]] === 1) {
      return i;
    }
  }
  return -1;
};
// @lc code=end
