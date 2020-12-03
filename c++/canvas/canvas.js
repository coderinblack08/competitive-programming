let stack = [];
for (let i = 0; i <= 37; i++) {
  if (i === 0) {
    stack.push(7);
  } else {
    const newStack = [];
    stack.forEach((number) => {
      newStack.push(number - 1, number + 1);
    });
    stack = newStack;
  }
}
console.log(stack);
