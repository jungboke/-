#include <bits/stdc++.h>
#define INF 1000000009
using namespace std;
long long d[100001][4];
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=100000;i++) {
    for(int j=1;j<=3;j++) {
      if(i==j) d[i][j] = 1;
      for(int k=1;k<=3;k++) {
        if(k==j) continue;
        if(i-j>=0) {
          d[i][j] += d[i-j][k];
        }
        d[i][j]%=INF; 
      }
    }
  }
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    cout << (d[x][1]+d[x][2]+d[x][3])%INF << '\n';
  }
  return 0;
}
