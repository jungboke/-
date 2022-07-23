#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d1[1001];
int d2[1001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    d1[i] = 1;
    d2[i] = 1;
  }
  for(int i=1;i<=n;i++) {
    for(int j=0;j<i;j++) {
      if(a[j]<a[i]) {
        d1[i] = max(d1[i],d1[j]+1);
      }
    }
  }
  for(int i=n;i>=1;i--) {
    for(int j=n;j>i;j--) {
      if(a[j]<a[i]) {
        d2[i] = max(d2[i],d2[j]+1);
      }
    }
  }
  int maxi = -1;
  for(int i=1;i<=n;i++) {
    int sum = d1[i]+d2[i]-1;
    maxi = max(maxi,sum);
  }
  cout << maxi << '\n';
  return 0;
}
