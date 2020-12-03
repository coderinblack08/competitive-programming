const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  let input = await fs.readFile(path.join(__dirname, './2020-2.txt'), 'utf8');
  input = input.split('\n').map((x) => x.split(' '));

  let answer = 0;

  input.forEach((line) => {
    const [min, max] = line[0].split('-');
    const letter = line[1].replace(':', '');
    const word = line[2];

    // const count = word.split('').reduce((acc, val) => {
    //   if (val === letter) {
    //     acc++;
    //     return acc;
    //   }
    // }, 0);

    // PART 1:

    // let count = 0;
    // word.split('').forEach((val) => {
    //   if (letter === val) {
    //     count++;
    //   }
    // });

    // if (count >= min && count <= max) {
    //   answer++;
    // }

    // PART 2:
    const section = word.substring(min - 1, max).split('');
    let count = 0;

    for (let i = 0; i < section.length; i++) {
      console.log(section[i], section[i] === letter);
      if (section[i] === letter) {
        if (count > 0) {
          console.log('-');
          break;
        } else {
          count++;
        }
      } else if (i === section.length - 1) {
        if (count === 1) {
          answer++;
        }
        console.log('-');
      }
    }
  });

  console.log(answer);
};

main();
