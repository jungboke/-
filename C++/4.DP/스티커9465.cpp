#include <bits/stdc++.h>
using namespace std;
int a[100001][2];
int d[100001][3];
int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    for(int i=0;i<=n;i++) {
      memset(a[i],0,sizeof(a[i]));
      memset(d[i],0,sizeof(d[i]));
    }
    for(int i=1;i<=n;i++) cin >> a[i][0];
    for(int i=1;i<=n;i++) cin >> a[i][1]; 
    for(int i=1;i<=n;i++) {
      d[i][0] = max({d[i-1][0],d[i-1][1],d[i-1][2]});
      d[i][1] = max(d[i-1][0],d[i-1][2]) + a[i][0];
      d[i][2] = max(d[i-1][0],d[i-1][1]) + a[i][1];
    }
    cout << max({d[n][0],d[n][1],d[n][2]}) << '\n';
  }
  return 0;
}