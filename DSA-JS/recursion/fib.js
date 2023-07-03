// O(2^n) -> recursive
const recursiveFib = (n) => {
  if (n < 2) {
    return n;
  }
  return recursiveFib(n - 1) + recursiveFib(n - 2);
};

console.log(recursiveFib(0));
console.log(recursiveFib(1));
console.log(recursiveFib(6));

//O(n)
const fibonacci = (n) => {
  const fib = [0, 1];
  for (let i = 2; i < n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return fib;
};

// console.log(fibonacci(2));
// console.log(fibonacci(5));
// console.log(fibonacci(10));
