#include <bits/stdc++.h>
using namespace std;

int main()
{

  int size;
  cin >> size;

  int array[size];

  for (int i = 0; i < size; i++)
  {
    cin >> array[i];
  }

  char c;
  cout << "do you want to search: (Y/N) ";
  cin >> c;

  while (toupper(c) == 'Y')
  {
    int checkValue;
    cout << "Enter the value you want to search: ";
    cin >> checkValue;

    int flag = 0;

    for (int i = 0; i < size; i++)
    {
      if (array[i] == checkValue)
      {
        flag = 1;
        cout << i << "th index " << i + 1 << " position" << endl;
      }
    }

    if (flag == 0)
      cout << "Not found" << endl;

    cout << "Do you want to continue searching: (Y/N) ";
    cin >> c;
  }

  return 0;
}