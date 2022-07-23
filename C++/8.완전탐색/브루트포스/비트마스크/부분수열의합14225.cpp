#include <bits/stdc++.h>
using namespace std;
vector<int> a;
bool check[2000001];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for(int i=0;i<(1<<n);i++) {
    int sum = 0;
    for(int j=0;j<n;j++) {
      if((i&(1<<j))!=0) {
        sum += a[j];
      }
    }
    check[sum] = true;
  }
  for(int i=1;i<=2000000;i++) {
    if(check[i]==false) {
      cout << i << '\n';
      break;
    }
  }
  return 0;
}