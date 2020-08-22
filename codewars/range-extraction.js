const solution = (list) => {
  const ranges = list.reduce((acc, num, index) => {
    if (index === 0) acc.push([num]);
    if (acc[acc.length - 1][acc[acc.length - 1].length - 1] === num - 1) {
      acc[acc.length - 1].push(num);
    } else if (index !== 0) {
      acc.push([num]);
    }
    return acc;
  }, []);
  return ranges
    .reduce((acc, arr) => {
      if (arr.length === 1) acc.push(arr[0]);
      else if (arr.length === 2) {
        acc.push(arr[0]);
        acc.push(arr[1]);
      } else {
        acc.push(arr[0] + '-' + arr[arr.length - 1]);
      }
      return acc;
    }, [])
    .join(',');
};

console.log(
  solution([
    -6,
    -3,
    -2,
    -1,
    0,
    1,
    3,
    4,
    5,
    7,
    8,
    9,
    10,
    11,
    14,
    15,
    17,
    18,
    19,
    20,
  ]),
  '-6,-3-1,3-5,7-11,14,15,17-20'
);
