/*
 * @lc app=leetcode id=204 lang=javascript
 *
 * [204] Count Primes
 */

// @lc code=start
/**
 * @param {number} n
 * @return {number}
 */
const countPrimes = function (n) {
  let primes = 0;
  const notPrime = new Array(n).fill(false);
  for (let i = 2; i < n; i++) {
    if (!notPrime[i]) {
      primes++;
      for (let j = 2; j * i < n; j++) {
        notPrime[i * j] = true;
      }
    }
  }
  return primes;
};
// @lc code=end
