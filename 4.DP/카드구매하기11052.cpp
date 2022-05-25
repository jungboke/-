#include <bits/stdc++.h>
using namespace std;
int a[10001];
int d[1001];

int go(int n) {
  if(n==0) return 0;
  if(d[n]>0) return d[n];
  for(int i=1;i<=n;i++) {
    d[n] = max(d[n],go(n-i)+a[i]);
  }
  return d[n];
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    int x;
    cin >> x;
    a[i] = x;
  }
  
  cout << go(n) << '\n';
  return 0;
}