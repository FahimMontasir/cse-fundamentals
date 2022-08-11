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

  // size1 ---> pos
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
    for (int i = size-1; i >= pos; i--)
    {
      /* code */
    }
    
  }

  return 0;
}