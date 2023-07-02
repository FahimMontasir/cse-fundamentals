const arr = [1, 2, 3, "fahim"];

arr.push(4); // O(1)
arr.unshift(0); // O(n)
arr.pop(); // O(1) constant
arr.shift(); // O(n) linear

for (const item of arr) {
  console.log(item);
}

// O(n) learn more array method eg. map, filter, reduce, concat, slice, splice etc.
