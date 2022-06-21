#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
vector<int> result;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    a.push_back(make_pair(x,y));
  }
  for(int i=1;i<(1<<n);i++) {
    int sum = 0;
    int mul = 1;
    for(int j=0;j<n;j++) {
      if(i&(1<<j)) {
        sum += a[j].second;
        mul *= a[j].first;
      }
    }
    result.push_back(abs(sum-mul));
  }
  cout << *min_element(result.begin(),result.end()) << '\n';
  return 0;
}