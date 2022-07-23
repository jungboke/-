#include <bits/stdc++.h>
using namespace std;
int d[1001][10];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  d[0][0] = 1;
  for(int i=1;i<=n;i++) {
    for(int j=0;j<=9;j++) {
      for(int c=0;c<=j;c++) {
        d[i][j] += d[i-1][c];
        d[i][j]%=10007;
      }
    }
  }
  int answer = 0;
  for(int i=0;i<=9;i++) {
    answer += d[n][i];
  }
  cout << answer%10007 << '\n';
  return 0;
}
