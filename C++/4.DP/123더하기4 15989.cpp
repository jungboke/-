#include <bits/stdc++.h>
using namespace std;
int d[10001];
int num[] = {1,2,3};

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;

  d[0] = 1;
  for(int c=0;c<3;c++) {
    for(int i=1;i<=10000;i++) {
      if(i-num[c]>=0) d[i] += d[i-num[c]];
    }
  }
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    cout << d[x] << '\n';
  }
  return 0;
}