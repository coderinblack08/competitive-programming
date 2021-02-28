const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './5.txt'), 'utf-8');
  let lines = input.split('\n');

  const binaryLines = lines.map((line) => {
    return line
      .replace(/F/g, '0')
      .replace(/B/g, '1')
      .replace(/L/g, '0')
      .replace(/R/g, '1');
  });

  binaryLines.sort().reverse();

  const row = parseInt(binaryLines[0].slice(0, 7), 2);
  const column = parseInt(binaryLines[0].slice(7, 10), 2);

  console.log(row * 8 + column);
};

main();
