#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[1001][3];
int d[1001][3];


int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  int mini = INF;
  for(int i=1;i<=n;i++) {
    for(int j=0;j<3;j++) {
      cin >> a[i][j];
    }
  }
  for(int k=0;k<3;k++) {
    for(int c=0;c<3;c++) {
      if(c==k) d[1][c] = a[1][c];
      else d[1][c] = INF;
    }
    for(int i=2;i<=n;i++) {
      d[i][0] = min(d[i-1][1],d[i-1][2]) + a[i][0];
      d[i][1] = min(d[i-1][0],d[i-1][2]) + a[i][1];
      d[i][2] = min(d[i-1][0],d[i-1][1]) + a[i][2];
    }
    for(int i=0;i<3;i++) {
      if(i==k) continue;
      mini = min(mini,d[n][i]);
    }
  }
  cout << mini << '\n';
  return 0;
}