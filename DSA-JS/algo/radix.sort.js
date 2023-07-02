function countingSort(array, size, place) {
  const output = new Array(size + 1);
  let max = array[0];
  for (let i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  const count = new Array(max + 1).fill(0);

  for (let i = 0; i < max; ++i) {
    count[i] = 0;
  }

  for (let i = 0; i < size; i++) {
    count[Math.floor((array[i] / place) % 10)]++;
  }

  for (let i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (let i = size - 1; i >= 0; i--) {
    output[count[Math.floor((array[i] / place) % 10)] - 1] = array[i];
    count[Math.floor((array[i] / place) % 10)]--;
  }

  for (let i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

function getMax(array, size) {
  let max = array[0];
  for (let i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

function radixSort(array, size) {
  let max = getMax(array, size);

  for (let place = 1; Math.floor(max / place) > 0; place *= 10) {
    countingSort(array, size, place);
  }
}

const data = [121, 432, 564, 23, 1, 45, 788];
const size = data.length;
radixSort(data, size);
console.log(data);
