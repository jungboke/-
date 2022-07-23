#include <bits/stdc++.h>
using namespace std;
int t[1500001];
int p[1500001];
int d[1500001];

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> t[i] >> p[i];
  }
  for(int i=1;i<=n;i++) {
    d[i+t[i]] = max(d[i+t[i]],d[i]+p[i]);
    d[i+1] = max(d[i+1],d[i]);
  }
  cout << d[n+1] << '\n';
  return 0;
}