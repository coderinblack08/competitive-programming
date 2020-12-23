const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './10.txt'), 'utf-8');
  let lines = input.split('\n').map((x) => parseInt(x));
  const cache = {};

  lines.push(0, Math.max(...lines) + 3);
  lines = lines.sort((a, b) => a - b);

  const dp = (n) => {
    if (n === lines.length - 1) {
      return 1;
    }
    if (n in cache) {
      return cache[n];
    }
    let ans = 0;
    for (let i = n + 1; i < lines.length; i++) {
      if (lines[i] - lines[n] <= 3) {
        ans += dp(i);
      }
    }
    cache[n] = ans;
    return ans;
  };

  console.log(dp(0));
};

main();
