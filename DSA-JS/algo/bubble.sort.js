// O(n^2)
const bubbleSort = (arr) => {
  let swapped;
  do {
    swapped = false;
    for (let i = 0; i < arr.length - 1; i++) {
      if (arr[i] > arr[i + 1]) {
        let temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
        swapped = true;
      }
    }
  } while (swapped);
};

const arr = [4, 1, -3, 5];
const arr2 = [1, 2, 5, 7];

// bubbleSort(arr);
bubbleSort(arr);
console.log(arr);
