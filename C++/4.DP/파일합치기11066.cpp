#include <bits/stdc++.h>
using namespace std;
int a[501];
int d[501][501];

int go(int x, int y) {
  if(x==y) return 0;
  if(d[x][y]!=-1) return d[x][y];
  int sum = 0;
  for(int i=x;i<=y;i++) {
    sum += a[i];
  }
  for(int k=x;k<y;k++) {
    if(d[x][y]==-1||d[x][y]>go(x,k)+go(k+1,y)+sum) {
      d[x][y] = go(x,k)+go(k+1,y)+sum;
    }
  }
  return d[x][y];
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) memset(d[i],-1,sizeof(d[i]));
    for(int i=1;i<=n;i++) {
      cin >> a[i];
    }
    cout << go(1,n) << '\n';
  }
  return 0;
}
