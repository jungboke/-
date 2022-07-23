// #include <bits/stdc++.h>
// using namespace std;
// int d[1000001];

// int go(int n) {
//   if(n==1) return 0;
//   if(d[n]>0) return d[n];
//   d[n] = go(n-1) + 1;
//   if(n%2==0) {
//     d[n] = min(d[n],go(n/2)+1);
//   }
//   if(n%3==0) {
//     d[n] = min(d[n],go(n/3)+1);
//   }
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
#define INF 1000000000
using namespace std;
int d[1000001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[1] = 0;
  for(int i=2;i<=n;i++) {
    d[i] = INF;
    if(i%2==0) d[i] = min(d[i],d[i/2]+1);
    if(i%3==0) d[i] = min(d[i],d[i/3]+1);
    d[i] = min(d[i],d[i-1]+1);
  }
  cout << d[n] << '\n';
  return 0;
}
