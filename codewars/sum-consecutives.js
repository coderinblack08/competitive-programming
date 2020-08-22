const sumConsecutives = (list) => {
  const duplicates = list.reduce((acc, num) => {
    acc.hasOwnProperty(num) ? acc[num]++ : (acc[num] = 1);
    return acc;
  }, {});
  const result = [];
  for (const property in duplicates) {
    result.push(property * duplicates[property]);
  }
  return result;
};

console.log(sumConsecutives([1, 4, 4, 4, 0, 4, 3, 3, 1]), [1, 12, 0, 4, 6, 1]);
console.log(sumConsecutives([1, 1, 7, 7, 3]), [2, 14, 3]);
console.log(sumConsecutives([-5, -5, 7, 7, 12, 0]), [-10, 14, 12, 0]);
console.log(sumConsecutives([3, 3, 3, 3, 1]), [12, 1]);
