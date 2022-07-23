// #include <bits/stdc++.h>
// using namespace std;
// int a[10001];
// int d[1001];

// int go(int n) {
//   if(n==0) return 0;
//   if(d[n]>0) return d[n];
//   for(int i=1;i<=n;i++) {
//     if(d[n]==-1||d[n]>go(n-i)+a[i]) {
//       d[n] = go(n-i)+a[i];
//     }
//   }
//   return d[n];
// }

// int main(int argc, char const *argv[])
// {
//   int n;
//   cin >> n;
//   memset(d,-1,sizeof(d));
//   for(int i=1;i<=n;i++) {
//     int x;
//     cin >> x;
//     a[i] = x;
//   }
  
//   cout << go(n) << '\n';
//   return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int d[1001];
int a[1001];
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for(int i=1;i<=n;i++) {
    d[i] = INF;
    for(int j=1;j<=i;j++) {
      d[i] = min(d[i],d[i-j]+a[j]);
    }
  }
  cout << d[n] << '\n';
  return 0;
}
