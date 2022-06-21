#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1,0,-1};
char a[8][8];

int bfs() {
  queue<pair<int,int>> q;
  q.push(make_pair(7,0));
  int t = -1;
  while(!q.empty()) {
    int size = q.size();
    t+=1;
    if(t==7) break;
    for(int i=0;i<size;i++) {
      int x,y;
      tie(x,y) = q.front();
      q.pop();
      for(int i=0;i<9;i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<8&&ny>=0&&ny<8) {
          if(nx-t>=0&&a[nx-t][ny]=='#') continue;
          if(nx-t-1>=0&&a[nx-t-1][ny]=='#') continue;
          q.push(make_pair(nx,ny));
        }
      }
    }
  }
  if(!q.empty()) return 1;
  else return 0;
}

int main(int argc, char const *argv[])
{
  for(int i=0;i<8;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<8;j++) {
      a[i][j] = temp[j];
    }
  }
  int answer = bfs();
  cout << answer << '\n';
  return 0;
}
