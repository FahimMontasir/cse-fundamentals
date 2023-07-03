// O(n)
const recursiveFactorial = (n) => {
  if (n === 0) {
    return 1;
  }
  return n * recursiveFactorial(n - 1);
};

console.log(recursiveFactorial(0));
console.log(recursiveFactorial(1));
console.log(recursiveFactorial(5));

// O(n)
const factorial = (n) => {
  let result = 1;
  for (let i = 2; i <= n; i++) {
    result = result * i;
  }
  return result;
};

// console.log(factorial(4));
// console.log(factorial(1));
