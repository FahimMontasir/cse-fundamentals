function partition(array, low, high) {
  const pivot = array[high];
  let i = low - 1;

  for (let j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      [array[i], array[j]] = [array[j], array[i]];
    }
  }

  [array[i + 1], array[high]] = [array[high], array[i + 1]];
  return i + 1;
}

function quickSort(array, low, high) {
  if (low < high) {
    const pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}

const data = [8, 7, 2, 1, 0, 9, 6];
const size = data.length;
quickSort(data, 0, size - 1);
console.log(data);
