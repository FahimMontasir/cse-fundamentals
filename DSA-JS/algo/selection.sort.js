const selectionSort = (arr) => {
  const size = arr.length;
  for (let step = 0; step < size - 1; step++) {
    let minIndex = step;
    for (let i = step; i < size - 1; i++) {
      // select the minimum element in each loop
      if (arr[i] < arr[minIndex]) {
        minIndex = i;
      }
    }
    // put min at the correct position
    const temp = arr[step];
    arr[step] = arr[minIndex];
    arr[minIndex] = temp;
  }
};

const arr = [4, 1, -3, 5];
selectionSort(arr);
console.log(arr);
