#include <bits/stdc++.h>
using namespace std;

int fly_check(vector<vector<int>> a, int x, int y, int m) {
  int result = 0;
  for(int i=0;i<m;i++) {
    for(int j=0;j<m;j++) {
      result += a[x+i][y+j];
    }
  }
  return result;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int cnt = t;
  while(t--) {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++) {
      for(int j=0;j<n;j++) {
        cin >> a[i][j];
      }
    }
    int answer = 0;
    for(int i=0;i<n-m+1;i++) {
      for(int j=0;j<n-m+1;j++) {
        int sum = fly_check(a,i,j,m);
        answer = max(answer,sum);
      }
    }
    cout << '#' << cnt-t << ' ' << answer << '\n';
  }
  return 0;
}
