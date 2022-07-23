// #include <bits/stdc++.h>
// using namespace std;
// int a[1001];
// int d[1001];

// int main(int argc, char const *argv[])
// {
//   int n;
//   cin >> n;
//   for(int i=0;i<n;i++) {
//     cin >> a[i];
//     d[i] = 1;
//   }
//   for(int i=0;i<1000;i++) {
//     for(int j=0;j<i;j++) {
//       if(a[j]<a[i]) d[i] = max(d[i],d[j]+1);
//     }
//   }
//   int maxi = -1;
//   for(int i=0;i<n;i++) {
//     maxi = max(maxi,d[i]);
//   }
//   cout << maxi << '\n';
//   return 0;
// }
#include <bits/stdc++.h>
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
  d[1] = 1;
  for(int i=2;i<=n;i++) {
    d[i] = 1;
    for(int j=1;j<i;j++) {
      if(a[i]>a[j]) d[i] = max(d[i],d[j]+1);
    }
  }
  int maxi = -1;
  for(int i=1;i<=n;i++) {
    maxi = max(maxi,d[i]);
  }
  cout << maxi << '\n';
  return 0;
}