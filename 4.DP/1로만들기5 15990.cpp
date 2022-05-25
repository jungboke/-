#include <bits/stdc++.h>
#define INF 1000000009
#define LIMIT 100000
using namespace std;
long long d[100001][4];

int main(int argc, char const *argv[])
{
  for(int i=1;i<=LIMIT;i++) {
    if(i-1>=0) {
      d[i][1] = (d[i-1][2] + d[i-1][3])%INF;
      if(i==1) d[i][1] = 1;
    }
    if(i-2>=0) {
      d[i][2] = (d[i-2][1] + d[i-2][3])%INF;
      if(i==2) d[i][2] = 1;
    }
    if(i-3>=0) {
      d[i][3] = (d[i-3][1] + d[i-3][2])%INF;
      if(i==3) d[i][3] = 1;
    }
  }

  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << (d[n][1] + d[n][2] + d[n][3])%INF << '\n';
  }
  return 0;
}