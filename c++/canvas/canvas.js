let expression = '8/4-2+5/3+10/24/2+10-16/2'.split('');

for (let i = 0; i < expression.length; i++) {
  for (let j = i + 1; j < expression.length; j++) {
    let newExpression = [
      ...expression.slice(0, i),
      '(',
      ...expression.slice(i, j),
      ')',
      ...expression.slice(j),
    ];
    if (eval(newExpression.join('') === 0)) {
      console.log(newExpression.join(''));
    }
  }
}
