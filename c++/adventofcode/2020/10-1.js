const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './10.txt'), 'utf-8');
  let lines = input.split('\n').map((x) => parseInt(x));

  lines.push(0, Math.max(...lines) + 3);
  lines = lines.sort((a, b) => a - b);

  let a1 = 0;
  let a3 = 0;
  for (let i = 0; i < lines.length - 1; i++) {
    const diff = lines[i + 1] - lines[i];
    if (diff === 1) {
      a1++;
    } else if (diff === 3) {
      a3++;
    }
  }
  console.log(a1 * a3);
};

main();
