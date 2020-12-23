const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  let ans = 0;
  const input = await fs.readFile(path.join(__dirname, './6.txt'), 'utf8');
  let lines = input.split('\n\n').map((x) => x.split('\n'));

  lines.forEach((line) => {
    const answers = line.reduce((acc, val) => {
      val.split('').forEach((x) => {
        acc[x] = true;
      });
      return acc;
    }, {});
    ans += Object.values(answers).length;
  });
  console.log(ans);
};

main();
