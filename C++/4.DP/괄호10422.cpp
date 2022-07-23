#include <bits/stdc++.h>
#define INF 1000000007
using namespace std;
long long d[5001];

long long go(int n) {
  if(n==0) return 1;
  if(d[n]!=-1) return d[n];
  d[n] = 0;
  for(int i=2;i<=n;i++) {
    d[n] += go(i-2)*go(n-i);
    d[n]%=INF;
  }
  return d[n];
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(d,-1,sizeof(d));
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n%2==1) cout << 0 << '\n';
    else cout << go(n) << '\n';
  }
  return 0;
}
