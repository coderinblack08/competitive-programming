const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './8.txt'), 'utf-8');
  const lines = input.split('\n');

  for (let i = 0; i < lines.length; i++) {
    let [op2, arg2] = lines[i].split(' ');
    if (op2 !== 'acc') {
      lines[i] = `${op2 === 'nop' ? 'jmp' : 'nop'} ${arg2}`;
    }

    const seen = new Set();
    let t = 0,
      idx = 0,
      acc = 0;
    while (0 <= idx < lines.length && t < 1000) {
      t++;
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
    if (idx === lines.length) {
      console.log(acc);
    }
  }
};

main();
