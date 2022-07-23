#include <bits/stdc++.h>
using namespace std;

int sdoku_check(vector<vector<int>> a) {
  for(int i=0;i<9;i++) {
    set<int> s;
    for(int j=0;j<9;j++) {
      s.insert(a[i][j]);
    }
    if(s.size()!=9) return 0;
  }
  for(int j=0;j<9;j++) {
    set<int> s;
    for(int i=0;i<9;i++) {
      s.insert(a[i][j]);
    }
    if(s.size()!=9) return 0;
  }
  set<int> temp[3][3];
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      temp[i/3][j/3].insert(a[i][j]);
    }
  }
  for(int i=0;i<3;i++) {
    for(int j=0;j<3;j++) {
      if(temp[i][j].size()!=9) return 0;
    }
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  int cnt = t;
  while(t--) {
    vector<vector<int>> a(9,vector<int>(9,0));
    for(int i=0;i<9;i++) {
      for(int j=0;j<9;j++) {
        cin >> a[i][j];
      }
    }
    int answer = sdoku_check(a);
    cout << '#' << cnt-t << ' ' << answer << '\n';
  }
  return 0;
}
