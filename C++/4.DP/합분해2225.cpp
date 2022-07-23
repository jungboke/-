#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
long long d[201][201];
int main(int argc, char const *argv[])
{
  int n,k;
  cin >> n >> k;
  for(int i=1;i<=k;i++) {
    for(int j=0;j<=n;j++) {
      for(int c=0;c<=j;c++) {
        if(i==1) d[i][j] = 1;
        d[i][j] += d[i-1][j-c];
        d[i][j]%=INF;
      }
    }
  }
  cout << d[k][n] << '\n';
  return 0;
}
