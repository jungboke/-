#include <bits/stdc++.h>
using namespace std;
int a[1000001];

// 0 : 소수, 1 : 소수아님
int main(int argc, char const *argv[])
{
  a[1] = 1;
  for(int i=2;i<=1000000;i++) {
    if(a[i]==0) {
      for(int j=i+i;j<=1000000;j+=i) {
        a[j] = 1;
      }
    }
  }
  int m,n;
  cin >> m >> n;
  for(int i=m;i<=n;i++) {
    if(a[i]==0) cout << i << '\n';
  }
  return 0;
}