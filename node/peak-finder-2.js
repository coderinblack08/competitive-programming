// Problem Statement: 2D Peak Finder Algorithm
// Key concept: Divide and Conquer Strategy
// MIT Link: https://courses.csail.mit.edu/6.006/spring11/lectures/lec02.pdf

const matrix = [
  [10, 8, 10, 10],
  [14, 13, 12, 11],
  [15, 9, 11, 21],
  [16, 17, 19, 20]
],
  list = [];
// Find Max in each row
matrix.forEach(i => list.push(Math.max(...i)));
// Find Global Maximum
console.log(Math.max(...list));