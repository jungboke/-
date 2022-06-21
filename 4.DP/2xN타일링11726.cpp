// #include <bits/stdc++.h>
// using namespace std;
// int d[1001];

// int go(int n) {
//   if(n==0||n==1) {
//     d[n] = 1;
//     return d[n];
//   }
//   if(d[n]>0) return d[n];
//   d[n] = (go(n-1) + go(n-2))%10007;
//   return d[n];
// }

// int main(int argc, char const *argv[])
// {
//   int n;
//   cin >> n;
//   cout << go(n) << '\n';
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int d[1001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[0] = 1;
  d[1] = 1;
  for(int i=2;i<=n;i++) {
    d[i] = d[i-1]+d[i-2];
    d[i] %= 10007;
  }
  cout << d[n] << '\n';
  return 0;
}
