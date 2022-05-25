#include <bits/stdc++.h>
using namespace std;
int a[100003];
int d1[100003];
int d2[100003];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  for(int i=1;i<=n;i++) {
    d1[i] = max(d1[i-1]+a[i],a[i]);
  }
  for(int i=n;i>=1;i--) {
    d2[i] = max(d2[i+1]+a[i],a[i]);
  }
  int maxi = d1[1];
  for(int i=2;i<=n;i++) {
    maxi = max(maxi,d1[i]);
  }
  for(int i=2;i<n;i++) {
    maxi = max(maxi,d1[i-1]+d2[i+1]);
  }
  cout << maxi << '\n';
  return 0;
}
