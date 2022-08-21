#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

void bubbleSort(int array[], int arrSize)
{
  for (int step = 0; step < arrSize; step++)
  {
    // it will iterate over this array six times
    int swapped = 0;
    cout << "Step " << step + 1 << ":" << endl;
    for (int i = 0; i < arrSize - step - 1; i++)
    {
      cout << "iteration " << i + 1 << ": ";
      printArr(array, arrSize);
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
        swapped = 1;
      }
      cout << " -> ";
      printArr(array, arrSize);
      cout << "\n";
    }
    if (swapped == 0)
      break;
  }
}

int main()
{
  // sorted in descending order
  int array[] = {11, 8, 5, 3, 2, 1};
  int arrSize = sizeof(array) / sizeof(array[0]);

  bubbleSort(array, arrSize);

  return 0;
}