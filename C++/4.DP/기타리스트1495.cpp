#include <bits/stdc++.h>
using namespace std;
int v[51];
int d[51][1001];

int main(int argc, char const *argv[])
{
  int n,s,m;
  cin >> n >> s >> m;
  for(int i=1;i<=n;i++) {
    cin >> v[i];
  }
  d[0][s] = 1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<=m;j++) {
      if(!d[i][j]) continue;
      if(j-v[i+1]>=0) d[i+1][j-v[i+1]] = 1;
      if(j+v[i+1]<=m) d[i+1][j+v[i+1]] = 1;
    }
  }
  int answer = -1;
  for(int i=0;i<=m;i++) {
    if(d[n][i]) answer = i;
  }
  cout << answer << '\n';
  return 0;
}
