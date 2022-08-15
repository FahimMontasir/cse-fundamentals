#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  for (int ti = 0; ti < t; ti++)
  {
    int n;
    cin >> n;
    int a[n];
    for (int ai = 0; ai < n; ai++)
    {
      cin >> a[ai];
    }
    // sorting - insertion
    for (int i = 1; i < n; i++)
    {
      int key = a[i];

      int j = i - 1;
      while (a[j] > key && j >= 0)
      {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = key;
    }

    int dl = 0;
    for (int p = 0; p < n - 1; p++)
    {
      if (a[p] == a[p + 1])
      {
        dl++;
      }
    }
    if (dl == n - 1)
      dl = 0;
    cout << dl << endl;
  }

  return 0;
}