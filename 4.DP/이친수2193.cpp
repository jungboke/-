// #include <bits/stdc++.h>
// using namespace std;
// long long d[91][2];

// int main(int argc, char const *argv[])
// {
//   for(int i=1;i<=90;i++) {
//     if(i==1) {
//       d[i][0] = 0;
//       d[i][1] = 1;
//     }
//     d[i][1] += d[i-1][0];
//     d[i][0] += d[i-1][1] + d[i-1][0];
//   }
//   int n;
//   cin >> n;
//   cout << d[n][0] + d[n][1] << '\n';
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;
long long d[100][2];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[1][1] = 1;
  for(int i=2;i<=n;i++) {
    d[i][1] = d[i-1][0];
    d[i][0] = d[i-1][0] + d[i-1][1];
  }
  cout << d[n][0]+d[n][1] << '\n';
  return 0;
}
