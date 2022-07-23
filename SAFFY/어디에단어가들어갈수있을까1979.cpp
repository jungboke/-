#include <bits/stdc++.h>
using namespace std;

int word_find(vector<vector<int>> a, int m) {
  int result = 0;
  int n = a.size();
  for(int i=0;i<n;i++) {
    int cnt = 0;
    for(int j=0;j<n;j++) {
      if(a[i][j]==1) cnt+=1;
      else {
        if(cnt==m) {
          result+=1;
        }
        cnt = 0;
      }
    }
    if(cnt==m) result+=1;
  }
  for(int j=0;j<n;j++) {
    int cnt = 0;
    for(int i=0;i<n;i++) {
      if(a[i][j]==1) cnt+=1;
      else {
        if(cnt==m) {
          result+=1;
        }
        cnt = 0;
      }
    }
    if(cnt==m) result+=1;
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
    int answer = word_find(a,m);
    cout << '#' << cnt-t << ' ' << answer << '\n';
  }
  return 0;
}