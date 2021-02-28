const fs = require('fs');
const path = require('path');

const countBags = (bags, name) => {
  let total = 0;
  const parent = bags[name];

  Object.entries(parent).forEach(([type, count]) => {
    total += count;
    total += countBags(bags, type) * count;
  });

  return total;
};

const main = async () => {
  const bags = {};
  const input = await fs.promises.readFile(
    path.join(__dirname, './7.txt'),
    'utf-8'
  );
  const lines = input.split('\n');
  lines.forEach((line) => {
    const [_, name] = line.match(/^(\w+ \w+) bags/);
    const contents = {};
    bags[name] = contents;

    const findContents = /(\d) ([a-z]+ [a-z]+) bags?/g;
    let matches = findContents.exec(line);

    while (matches) {
      const [_, count, type] = matches;
      contents[type] = parseInt(count);

      matches = findContents.exec(line);
    }
  });
  console.log(countBags(bags, 'shiny gold'));
};

main();
