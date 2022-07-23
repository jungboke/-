#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
char a[21][21];
bool alp[30];
int N,M;
int answer = 0;

void dfs(int x, int y, int cnt) {
  alp[a[x][y]-'A'] = true;
  bool flag = false;
  for(int i=0;i<4;i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0&&nx<N&&ny>=0&&ny<M) {
      if(alp[a[nx][ny]-'A']==false) {
        flag = true;
        dfs(nx,ny,cnt+1);
      }
    }
  }
  if(flag==false) {
    answer = max(answer,cnt);
  }
  alp[a[x][y]-'A'] = false;
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;M=m;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++) {
      a[i][j] = temp[j];
    }
  }
  dfs(0,0,1);
  cout << answer << '\n';
  return 0;
}