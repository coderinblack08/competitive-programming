const fs = require('fs').promises;
const path = require('path');

const check = (prev, curr) => {
  for (let i = 0; i < prev.length; i++) {
    for (let j = 0; j < prev.length; j++) {
      if (i !== j && prev[i] + prev[j] === curr) {
        return true;
      }
    }
  }
  return false;
};

const main = async () => {
  const input = await fs.readFile(path.join(__dirname + '/9.txt'), 'utf8');
  const lines = input.split('\n').map((x) => Number(x));

  let ans;
  const preamble = 25;
  for (let i = preamble; i < lines.length; i++) {
    if (!check(lines.slice(i - preamble, i), lines[i])) {
      ans = lines[i];
    }
  }

  for (let i = 0; i < lines.length; i++) {
    for (let j = i + 2; j < lines.length; j++) {
      const section = lines.slice(i, j);
      const sum = section.reduce((a, x) => (a += x), 0);
      if (sum === ans) {
        console.log(Math.max(...section) + Math.min(...section));
      }
    }
  }
};

main();
