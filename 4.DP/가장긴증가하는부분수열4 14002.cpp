#include <bits/stdc++.h>
using namespace std;
int a[1001];
int d[1001];
int c[1001];

void go(int idx) {
  if(idx==-1) {
    return;
  }
  go(c[idx]);
  cout << a[idx] << ' ';
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> a[i];
    d[i] = 1;
    c[i] = -1;
  }
  for(int i=0;i<1000;i++) {
    for(int j=0;j<i;j++) {
      if(a[j]<a[i]) {
        if(d[i]<d[j]+1) {
          d[i] = d[j]+1;
          c[i] = j;
        }
      }
    }
  }
  int maxi = -1;
  int max_idx = -1;
  for(int i=0;i<n;i++) {
    if(maxi<d[i]) {
      maxi = d[i];
      max_idx = i;
    }
  }
  cout << maxi << '\n';
  go(max_idx);
  return 0;
}