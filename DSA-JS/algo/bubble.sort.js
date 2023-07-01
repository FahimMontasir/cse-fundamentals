// perform the bubble sort
const bubbleSort = (arr) => {
  const size = arr.length;
  // loop thru to access the array elements
  for (let i = 0; i < size - 1; i++) {
    let swapped = false;
    // loop to compare array elements
    for (let j = 0; j < size - i - 1; j++) {
      // compare two adjacent elements
      // change -> to sort in descending order
      if (arr[j] > arr[j + 1]) {
        // swapping occurs if elements
        // are not in the intended order
        const temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;

        swapped = true;
      }
    }
    // no swapping means the array is already sorted
    // so no need for further comparison
    if (!swapped) {
      break;
    }
  }
};

const arr = [4, 1, -3, 5];
const arr2 = [1, 2, 5, 7];

// bubbleSort(arr);
bubbleSort(arr2);
console.log(arr2);
