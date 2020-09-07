/*
 * @lc app=leetcode id=278 lang=javascript
 *
 * [278] First Bad Version
 */

// @lc code=start
/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
const solution = function (isBadVersion) {
  /**
   * @param {integer} n Total versions
   * @return {integer} The first bad version
   */
  return function (n) {
    let left = 1,
      right = n;
    while (left < right) {
      const middle = left + Math.floor((right - left) / 2);
      if (!isBadVersion(middle)) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }
    return left;
  };
};
// @lc code=end
