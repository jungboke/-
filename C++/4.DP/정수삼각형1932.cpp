#include <bits/stdc++.h>
using namespace std;
int a[501][501];
int d[501][501];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    for(int j=0;j<i;j++) {
      cin >> a[i][j];
    }
  }
  d[1][0] = a[1][0];
  for(int i=2;i<=n;i++) {
    for(int j=0;j<i;j++) {
      if(j-1<0) d[i][j] = d[i-1][j] + a[i][j];
      else if(j+1>=i) d[i][j] = d[i-1][j-1] + a[i][j];
      else d[i][j] = max(d[i-1][j-1],d[i-1][j]) + a[i][j];
    }
  }
  int maxi = -1;
  for(int i=0;i<n;i++) {
    maxi = max(maxi,d[n][i]);
  }
  cout << maxi << '\n';
  return 0;
}