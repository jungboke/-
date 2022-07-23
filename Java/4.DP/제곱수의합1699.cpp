#include <bits/stdc++.h>
using namespace std;
int d[100001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) d[i] = -1;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=sqrt(i);j++) {
      int temp = i-pow(j,2);
      if(d[i]==-1||d[i]>d[temp]+1) d[i] = d[temp]+1;
    }
  }
  cout << d[n] << '\n';
  return 0;
}
