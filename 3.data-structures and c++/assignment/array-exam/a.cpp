// For improving performance in competitive programming , you have to practice a lot of problems
// Avishek took the above advice very seriously and decided to set a target for himself.
// -Avishek decides to solve at least 1010 problems every week for 44 weeks.
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int pblmSolved[4];
  for (int i = 0; i < 4; i++)
  {
    cin >> pblmSolved[i];
  }

  int taskDone = 0;
  for (int i = 0; i < 4; i++)
  {
    if (pblmSolved[i] >= 10)
    {
      taskDone++;
    }
  }

  cout << taskDone;
  return 0;
}
