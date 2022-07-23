#include <bits/stdc++.h>
#define INF 9901
using namespace std;
int d[100001][3];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[0][0] = 1;
  for(int i=1;i<=n;i++) {
    d[i][0] = d[i-1][0] + d[i-1][1] + d[i-1][2];
    d[i][1] = d[i-1][0] + d[i-1][2];
    d[i][2] = d[i-1][0] + d[i-1][1];
    d[i][0]%=INF;
    d[i][1]%=INF;
    d[i][2]%=INF;
  }

  cout << (d[n][0] + d[n][1] + d[n][2])%INF << '\n';
  return 0;
}