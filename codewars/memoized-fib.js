const fibonacci = ((cache = [0, 1]) => (n) =>
  n in cache ? cache[n] : (cache[n] = fibonacci(n - 1) + fibonacci(n - 2)))();

console.log(fibonacci(70), 190392490709135);
console.log(fibonacci(60), 1548008755920);
console.log(fibonacci(50), 12586269025);
