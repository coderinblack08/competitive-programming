const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './8.txt'), 'utf-8');
  const lines = input.split('\n');

  const seen = new Set();
  let idx = 0,
    acc = 0;
  while (!seen.has(idx)) {
    let [op, arg] = lines[idx].split(' ');
    arg = parseInt(arg);
    if (op === 'acc') {
      acc += arg;
    }
    seen.add(idx);
    if (op === 'jmp') {
      idx += arg;
    } else {
      idx++;
    }
  }
  console.log(acc);
};

main();
