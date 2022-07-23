#include <bits/stdc++.h>
using namespace std;
int w[101];
int v[101];
int d[101][100001];

int go(int n, int k) {
  if(n==1) {
    if(k>=w[1]) return v[1];
    else return 0;
  }
  if(d[n][k]!=-1) return d[n][k];
  if(k-w[n]<0) d[n][k] = go(n-1,k);
  else d[n][k] = max(go(n-1,k),go(n-1,k-w[n])+v[n]);
  return d[n][k];
}

int main(int argc, char const *argv[])
{
  int n,k;
  cin >> n >> k;
  for(int i=1;i<=n;i++) memset(d[i],-1,sizeof(d[i]));
  for(int i=1;i<=n;i++) {
    cin >> w[i] >> v[i];
  }
  cout << go(n,k) << '\n';
  return 0;
}