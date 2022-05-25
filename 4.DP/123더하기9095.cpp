#include <bits/stdc++.h>
using namespace std;
int d[13];

int go(int n) {
  if(n==0) return 1;
  if(d[n]>0) return d[n];
  d[n] += go(n-1);
  if(n-2>=0) d[n] += go(n-2);
  if(n-3>=0) d[n] += go(n-3);
  return d[n];
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    cout << go(n) << '\n';
  }
  return 0;
}