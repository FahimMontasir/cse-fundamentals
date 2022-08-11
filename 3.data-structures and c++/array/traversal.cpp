#include<bits/stdc++.h>
using namespace std;

// Traversing a data structure means: "visiting" or "touching" the elements of the structure, and doing something with the data. (Traversing is also sometimes called iterating over the data structure)

void PrintArray(int array[], int size){

  for (int i = 0; i < size; i++)
  {
    cout<<array[i]<<" ";
  }
  cout<<endl;
}

int main(){

  int array[50];

  int size;
  cin>>size;

  for (int i = 0; i < size; i++)
  {
    cin>>array[i];
  }
  
  PrintArray(array, size);

  return 0;
}