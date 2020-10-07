/**
 *
 * @param {number[]} array
 */
const isSortedAndHow = (array) => {
  return array.every((a, b) => b == 0 || a >= array[b - 1])
    ? 'yes, ascending'
    : array.every((a, b) => b == 0 || a <= array[b - 1])
    ? 'yes, descending'
    : 'no';
};
