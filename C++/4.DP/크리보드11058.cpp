#include <bits/stdc++.h>
using namespace std;
long long d[101];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    d[i] = d[i-1]+1;
    for(int j=1;j<=i-3;j++) {
      if(i-(2+j)>=0) {
        d[i] = max(d[i],d[i-(2+j)]*(j+1));
      }
    }
  }
  cout << d[n] << '\n';
  return 0;
}
