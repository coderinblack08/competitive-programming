const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  let input = await fs.readFile(path.join(__dirname + '/4.txt'), 'utf8');

  input = input.split('\n\n');

  const properties = ['byr', 'iyr', 'eyr', 'hgt', 'hcl', 'ecl', 'pid', 'cid'];

  let validPassports = input.reduce((acc, val) => {
    let found = new Set();

    properties.forEach((property) => {
      if (val.includes(`${property}:`)) {
        found.add(property);
      }
    });

    if (
      found.size === properties.length ||
      (found.size === properties.length - 1 && !found.has('cid'))
    ) {
      acc++;
    }
    return acc;
  }, 0);

  console.log('Part 1: ' + validPassports);
};

main();
