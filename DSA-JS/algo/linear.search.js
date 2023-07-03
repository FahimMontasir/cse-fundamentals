// O(n)
const linearSearch = (arr, target) => {
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] === target) {
      return i;
    }
  }
  return -1;
};

console.log(linearSearch([1, 5, 2, 10], 5));
console.log(linearSearch([1, 5, 2, 10, 11], 11));
console.log(linearSearch([1, 5, 2, 10, 11], 0));
