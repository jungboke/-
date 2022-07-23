// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     int five = n/5;
//     int rem = n%5;
//     while(rem%2!=0&&five>=0)
//     {
//         rem+=5;
//         five--;
//     }
//     if(five<0) cout << -1 << '\n';
//     else cout << five+(rem/2) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int five = n/5;
  int rem = n%5;
  while(rem%2!=0&&five>=0) {
    rem += 5;
    five--;
  }
  if(five==-1) cout << -1 << '\n';
  else cout << five+(rem/2) << '\n';
  return 0;
}