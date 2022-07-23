#include <bits/stdc++.h>
using namespace std;
int d[2001][2001];
int a[2001];

int go(int x, int y) {
  if(x==y) return 1;
  else if(x+1==y) {
    if(a[x]==a[y]) return 1;
    else return 0;
  }
  if(d[x][y]!=-1) return d[x][y];
  if(go(x+1,y-1)==1&&a[x]==a[y]) d[x][y] = 1;
  else d[x][y] = 0;
  return d[x][y];
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) memset(d[i],-1,sizeof(d[i]));
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  int m;
  cin >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    cout << go(x,y) << '\n';
  }
  return 0;
}
