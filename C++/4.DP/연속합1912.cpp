#include <bits/stdc++.h>
using namespace std;
int a[100001];
int d[100001];
int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    d[i] = a[i];
  }
  for(int i=1;i<n;i++) {
    d[i] = max(d[i],d[i-1]+a[i]);
  }
  int maxi = d[0];
  for(int i=0;i<n;i++) {
    maxi = max(maxi,d[i]);
  }
  cout << maxi << '\n';
  return 0;
}