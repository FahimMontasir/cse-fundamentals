#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n";
}

void insertionSort(int array[], int arrSize)
{
  for (int i = 1; i < arrSize; i++)
  {
    int key = array[i];
    cout << endl
         << "key: " << key << " i: " << i << endl;
    int j = i - 1;
    while (array[j] > key && j >= 0)
    {
      array[j + 1] = array[j];
      printArr(array, arrSize);
      j--;
    }
    array[j + 1] = key;
    printArr(array, arrSize);
  }
}

int main()
{

  int array[] = {5, 1, 3, 8, 2, 2};
  int arrSize = sizeof(array) / sizeof(array[0]);

  insertionSort(array, arrSize);

  return 0;
}