const lazyChain = (arg, invocations = []) => {
  const chain = { invoke, value };

  function value() {
    return invocations.reduce((finalValue, invocation) => {
      return finalValue[invocation.name](...invocation.args);
    }, arg);
  }

  function invoke(name, ...args) {
    invocations.push({ name, args });
    return chain;
  }

  return chain;
};

console.log(
  lazyChain('hello').invoke('toUpperCase').invoke('split', '').value(),
  ['H', 'E', 'L', 'L', 'O']
);

console.log(
  lazyChain([1, 2, 3])
    .invoke('map', (x) => x * x)
    .invoke('reverse')
    .value(),
  [9, 4, 1]
);
