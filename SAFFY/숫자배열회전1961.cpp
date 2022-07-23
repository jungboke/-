#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &a) {
  vector<vector<int>> tmp_a = a;
  int n = a.size();
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      tmp_a[i][j] = a[j][n-i-1];
    }
  }
  a = tmp_a;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int cnt = t;
  while(t--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<vector<int>> b[3];
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cin >> a[i][j];
      }
    }
    for(int i=0;i<3;i++) {
      rotate(a);
      b[i] = a;
    }
    cout << '#' << cnt-t << '\n';
    for(int i=0;i<n;i++) {
      for(int j=0;j<3;j++) {
        for(int k=0;k<n;k++) {
          cout << b[j][i][k];
        }
        cout << ' ';
      }
      cout << '\n';
    }
  }
  return 0;
}