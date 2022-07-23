#include <bits/stdc++.h>
using namespace std;

void vec_swap(vector<int> &a, vector<int> &b) {
  if(a.size()>=b.size()) return;
  vector<int> temp;
  temp = a;
  a = b;
  b = temp;
  return;
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  int cnt = t;
  while(t--) {
    int n,m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    int answer = 0;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    for(int i=0;i<m;i++) {
      int x;
      cin >> x;
      b.push_back(x);
    }
    vec_swap(a,b);
    int diff = a.size()-b.size();
    for(int i=0;i<=diff;i++) {
      int sum = 0;
      for(int j=0;j<b.size();j++) {
        sum += a[j+i]*b[j];
      }
      answer = max(answer,sum);
    }
    cout << "#" << cnt-t << ' ' << answer << '\n';
  }
  return 0;
}
