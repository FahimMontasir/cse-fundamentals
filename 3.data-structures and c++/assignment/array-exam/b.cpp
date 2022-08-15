#include <bits/stdc++.h>
using namespace std;

int main()
{
  // the  added the two lines below are for faster i/0 method
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int T, N, q, I, J;

  cin >> T;

  for (int ti = 1; ti <= T; ti++)
  {
    cin >> N >> q;
    int nArr[N];
    for (int i = 0; i < N; i++)
    {
      cin >> nArr[i];
    }
    cout << "Case " << ti << ":"
         << "\n";

    // main logic
    for (int qi = 0; qi < q; qi++)
    {
      cin >> I >> J;
      int minValue = nArr[I - 1];
      for (int i = I - 1; i < J; i++)
      {
        if (nArr[i] < minValue)
        {
          minValue = nArr[i];
        }
      }
      cout << minValue << "\n";
    }
  }

  return 0;
}