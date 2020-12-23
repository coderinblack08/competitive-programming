const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  const input = await fs.readFile(path.join(__dirname, './5.txt'), 'utf-8');
  let lines = input.split('\n');

  let binaryLines = lines.map((line) =>
    line
      .replace(/F/g, '0')
      .replace(/B/g, '1')
      .replace(/L/g, '0')
      .replace(/R/g, '1')
  );

  binaryLines = binaryLines.map((line) => {
    const row = parseInt(line.slice(0, 7), 2);
    const column = parseInt(line.slice(7, 10), 2);
    let id = row * 8 + column;

    id = +id.toString(10);

    return id;
  });

  binaryLines = binaryLines.sort((a, b) => a - b);
  const first = binaryLines[0],
    last = binaryLines[binaryLines.length - 1];
  let sum = ((last - first + 1) * (last + first)) / 2;
  binaryLines.forEach((val) => {
    sum -= val;
  });
  console.log(sum);
};

main();
