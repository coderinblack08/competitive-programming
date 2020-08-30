const operations = {
  '+': '+',
  '-': '-',
  '*': '*',
  $: '/',
};
const calculate = (expression, result = 0) => {
  return result;
};

console.log(calculate('5*5*5'), 125);

console.log(calculate('1'), 1);
console.log(calculate('1.1'), 1.1);

console.log(calculate('1+1'), 2);
console.log(calculate('1-1'), 0);
console.log(calculate('2$2$2'), 1);
console.log(calculate('2*2'), 4);

console.log(calculate('1.1+1.9'), 3);
console.log(calculate('9$4'), 2.25);
console.log(calculate('1.5*3'), 4.5);
console.log(calculate('5-43.2'), -38.2);

console.log(calculate('5+5+5+5'), 20);
console.log(calculate('5-5-5-5'), -10);
console.log(calculate('5*5*5*5'), 625);
console.log(calculate('5$5$5$5'), 0.04);

console.log(calculate('1+1-1'), 1);
console.log(calculate('5*6$2+5-10'), 10);

console.log(calculate('1*1*1*1*1*1$1$1$1$1+1-1+9-1'), 9);
console.log(calculate('80 + 5 - 5 + 1'), 81);

console.log(calculate('5*6$2&5-10'), '400: Bad request');
console.log(calculate('5/10'), '400: Bad request');
console.log(calculate('p'), '400: Bad request');
console.log(calculate('9^9'), '400: Bad request');
