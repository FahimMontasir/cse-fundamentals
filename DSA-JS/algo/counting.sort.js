const countingSort = (array) => {
  const size = array.length;

  // Find the maximum element in the array
  let max = array[0];
  for (let i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  // Create a count array and initialize it with zeros
  const count = new Array(max + 1).fill(0);

  // Store the count of each element
  for (let i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Modify the count array to store the cumulative count
  for (let i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Create an output array to store the sorted elements
  const output = new Array(size);

  // Find the index of each element of the original array in the count array
  // and place the elements in the output array
  for (let i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into the original array
  for (let i = 0; i < size; i++) {
    array[i] = output[i];
  }
};

const data = [4, 2, 2, 8, 3, 3, 1];
countingSort(data);
console.log(data);
