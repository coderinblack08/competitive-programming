const arr = [17, 3, 1, 2, 6, 5, 2, 9];
const findMode = (arr) => {
  const sortedArray = arr.sort((a, b) => a - b);
  return sortedArray.length % 2 === 0
    ? (sortedArray[sortedArray.length / 2] +
        sortedArray[sortedArray.length / 2 + 1]) /
        2
    : sortedArray[(sortedArray.length - 1) / 2];
};
console.log(findMode(arr));
