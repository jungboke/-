#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
long long d[101][10];

int main(int argc, char const *argv[])
{
  for(int i=1;i<=100;i++) {
    for(int j=0;j<=9;j++) {
      if(i==1&&j!=0) d[i][j] = 1;
      if(j-1>=0) d[i][j] += d[i-1][j-1];
      if(j+1<=9) d[i][j] += d[i-1][j+1];
      d[i][j]%=INF;
    }
  }
  int n;
  cin >> n;
  long long sum = 0;
  for(int i=0;i<=9;i++) {
    sum += d[n][i];
  }
  cout << sum%INF << '\n';
  return 0;
}