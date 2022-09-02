#include <bits/stdc++.h>
using namespace std;

void getFrequency(int arr[], int size)
{
  bool ch[size];

  for (int i = 0; i < size; i++)
  {
    ch[i] = 0;
  }

  for (int i = 0; i < size; i++)
  {
    if (ch[i] == 1)
    {
      continue;
    }
    int count = 1;
    for (int j = i + 1; j < size; j++)
    {
      if (arr[i] == arr[j])
      {
        ch[j] = 1;
        count++;
      }
    }
    cout << arr[i] << "=>" << count << endl;
  }
}

int main()
{
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  getFrequency(arr, n);

  return 0;
}