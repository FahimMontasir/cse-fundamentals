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

  if (pos<0 || pos>size-1)
  {
    cout<<"invalid index";
  }
  else
  { // last pos
    if(pos==size-1) size--;
    else{
      // pos+1 ---> size-1 //start pos or mid pos
      for (int i = pos+1; i < size; i++)
      {
        array[i-1] = array[i];
      }
      size--;
    }
  }

  cout<<"Array after the deletion: ";
  PrintArray(array, size);
  return 0;
}