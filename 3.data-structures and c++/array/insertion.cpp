#include<bits/stdc++.h>
using namespace std;

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

  int pos, value;
  cout<<"Value of pos: ";
  cin>>pos;
  cout<<"Value of the Insertion:";
  cin>>value;

  if (pos<0 || pos> size)
  {
    cout<<"invalid index";
  }
  else
  {
  // size1 (4) ---> pos (2) swapping
    // for (int i = size-1; i >= pos; i--)
    // {
    //   array[i+1]= array[i];
    // }
    // size ----> pos (5) ----> (2)
    array[size]= array[pos];
    array[pos] = value;
  }

  cout<<"Array after the insertion: ";
  PrintArray(array, size+1);
  return 0;
}