#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    d[i] = 1;
  }
  for(int i=0;i<1000;i++) {
    for(int j=0;j<i;j++) {
      if(a[j]<a[i]) d[i] = max(d[i],d[j]+1);
    }
  }
  int maxi = -1;
  for(int i=0;i<n;i++) {
    maxi = max(maxi,d[i]);
  }
  cout << maxi << '\n';
  return 0;
}
