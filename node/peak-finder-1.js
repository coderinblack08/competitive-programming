// Problem Statement: 1D Peak Finder Algorithm
// Key concept: Divide and Conquer Strategy
// MIT Link: https://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf

const list = [1, 2, 6, 5, 3, 7, 4];

const findPeak = (list, h) => {
  if (
    (list[h - 1] <= list[h] && list[h] >= list[h + 1]) ||
    h === 0 ||
    h === list.length
  )
    return list[h];
  else if (list[h - 1] > list[h]) return findPeak(list, h - 1);
  else if (list[h + 1] > list[h]) return findPeak(list, h + 1);
};
console.log(findPeak(list, Math.floor(list.length / 2)));
