const input = process.argv[2];

/**
 * @param {string} word - reverses pig latin
 */
const solve = (word) => {
  if (word.endsWith('yay')) {
    return word.slice(0, -3);
  } else {
    const temp = word.split('-');
    let ans = temp.shift();
    temp.forEach((x) => {
      ans = x.slice(0, -2) + ans;
    });
    return ans;
  }
};

const values = input.split(' ');
console.log(values.map((x) => solve(x)).join(' '));
