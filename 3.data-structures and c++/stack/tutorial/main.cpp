#include <bits/stdc++.h>
#include "MYSTACK.h"
using namespace std;

int main()
{
  Stack st;

  st.push(1);
  st.push(2);
  st.push(3);
  while (!st.empty())
  {
    cout << st.pop() << endl;
  }

  return 0;
}