const fs = require('fs').promises;
const path = require('path');

const main = async () => {
  let ans = 0;
  const input = await fs.readFile(path.join(__dirname, './6.txt'), 'utf8');
  let lines = input.split('\n\n').map((x) => x.split('\n'));

  lines.forEach((line) => {
    const answers = line.reduce((acc, val) => {
      val.split('').forEach((x) => {
        if (acc[x]) {
          acc[x]++;
        } else {
          acc[x] = 1;
        }
      });
      return acc;
    }, {});
    ans += Object.values(answers).filter((x) => x === line.length).length;
  });
  console.log(ans);
};

main();
