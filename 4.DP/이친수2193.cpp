#include <bits/stdc++.h>
using namespace std;
long long d[91][2];

int main(int argc, char const *argv[])
{
  for(int i=1;i<=90;i++) {
    if(i==1) {
      d[i][0] = 0;
      d[i][1] = 1;
    }
    d[i][1] += d[i-1][0];
    d[i][0] += d[i-1][1] + d[i-1][0];
  }
  int n;
  cin >> n;
  cout << d[n][0] + d[n][1] << '\n';
  return 0;
}
