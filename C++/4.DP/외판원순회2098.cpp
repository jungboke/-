#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int d[17][1000001];
int a[17][17];
int N;

int go(int x, int target) {
  if(target==(1<<N)-1) {
    if(a[x][0]==0) return INF;
    return a[x][0];
  }
  if(d[x][target]!=-1) return d[x][target];
  d[x][target] = INF;
  for(int i=0;i<N;i++) {
    if(a[x][i]==0) continue;
    if((target&(1<<i))==(1<<i)) continue;
    d[x][target] = min(d[x][target],a[x][i]+go(i,target|(1<<i)));
  }
  return d[x][target];
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  int mini = INF;
  memset(d,-1,sizeof(d));
  cout << go(0,1) << '\n';
  return 0;
}