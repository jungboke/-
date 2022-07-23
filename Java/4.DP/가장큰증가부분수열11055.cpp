#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    d[i] = a[i];
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<i;j++) {
      if(a[j]<a[i]) {
        d[i] = max(d[i],d[j]+a[i]);
      }
    }
  }
  int maxi = -1;
  for(int i=1;i<=n;i++) {
    maxi = max(maxi,d[i]);
  }
  cout << maxi << '\n';
  return 0;
}
