/*
 * @lc app=leetcode id=383 lang=javascript
 *
 * [383] Ransom Note
 */

// @lc code=start
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
const canConstruct = (ransomNote, magazine) => {
  const map = {};
  [...ransomNote].forEach((letter, _index) => {
    if (map.hasOwnProperty(letter)) {
      map[letter]++;
    } else {
      map[letter] = 1;
    }
  });
  const map2 = {};
  [...magazine].forEach((letter, _index) => {
    if (map2.hasOwnProperty(letter)) {
      map2[letter]++;
    } else {
      map2[letter] = 1;
    }
  });
  for (const letter in map) {
    const count = map[letter];
    if (map2.hasOwnProperty(letter)) {
      if (count > map2[letter]) {
        return false;
      }
    } else {
      return false;
    }
  }
  return true;
};
// @lc code=end
