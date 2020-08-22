const snail = (matrix) => {
  let result;
  while (matrix.length) {
    result = result ? result.concat(matrix.shift()) : matrix.shift();
    for (let i = 0; i < matrix.length; i++) {
      result.push(matrix[i].pop());
    }
    result = result.concat((matrix.pop() || []).reverse());
    for (let i = matrix.length - 1; i >= 0; i--) {
      result.push(matrix[i].shift());
    }
  }
  return result;
};

console.log(
  snail([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
  ]),
  [1, 2, 3, 6, 9, 8, 7, 4, 5]
);
