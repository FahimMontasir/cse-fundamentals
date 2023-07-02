const insertionSort = (arr) => {
  const size = arr.length;

  for (let step = 1; step < size; step++) {
    let key = arr[step];
    let j = step - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    while (j >= 0 && key < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    // Place key at after the element just smaller than it.
    arr[j + 1] = key;
  }
};

const arr = [4, 1, -3, 5];
insertionSort(arr);
console.log(arr);
