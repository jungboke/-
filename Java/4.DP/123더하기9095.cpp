// #include <bits/stdc++.h>
// using namespace std;
// int d[13];

// int go(int n) {
//   if(n==0) return 1;
//   if(d[n]>0) return d[n];
//   d[n] += go(n-1);
//   if(n-2>=0) d[n] += go(n-2);
//   if(n-3>=0) d[n] += go(n-3);
//   return d[n];
// }

// int main(int argc, char const *argv[])
// {
//   int t;
//   cin >> t;
//   while(t--) {
//     int n;
//     cin >> n;
//     cout << go(n) << '\n';
//   }
//   return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int d[11];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[0] = 1;
  d[1] = 1;
  d[2] = 2;
  for(int i=1;i<=10;i++) {
    d[i] = d[i-1]+d[i-2]+d[i-3];
  }
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    cout << d[x] << '\n';
  }
  return 0;
}
