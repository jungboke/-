#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[1001];
int d[1001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
    d[i] = INF;
  }
  d[1] = 0;
  for(int i=2;i<=n;i++) {
    for(int j=1;j<i;j++) {
      if(a[j]>=i-j) {
        d[i] = min(d[i],d[j] + 1);
      }
    }
  }
  if(d[n]==INF) cout << -1 << '\n';
  else cout << d[n] << '\n';
  return 0;
}
