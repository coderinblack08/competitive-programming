const value1 = process.argv[2];

const regex = /(-?\d+)?x\^2([+-]\d+)?x([+-]\d+)?=0/;
const [a, b, c] = regex
  .exec(value1)
  .slice(1, 4)
  .map((x) => parseInt(x));

const discrim = b ** 2 - 4 * a * c;

const format = (a) => {
  a = a.toString();
  const [left, right] = a.split('.');
  return left + '.' + right.slice(0, 5);
};

if (discrim < 0) {
  console.log('imaginary,imaginary');
} else {
  console.log(
    format((-1 * b + Math.sqrt(discrim)) / (2 * a)) +
      ',' +
      format((-1 * b - Math.sqrt(discrim)) / (2 * a))
  );
}
