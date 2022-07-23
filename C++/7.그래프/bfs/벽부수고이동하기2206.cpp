#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[1001][1001];
int dist[1001][1001][2];
int N,M;

void bfs() {
  memset(dist,-1,sizeof(dist));
  queue<tuple<int,int,int>> q;
  q.push(make_tuple(0,0,1));
  dist[0][0][1] = 1;
  while(!q.empty()) {
    int x,y,z;
    tie(x,y,z) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<M) {
        if(a[nx][ny]==0&&dist[nx][ny][z]==-1) {
          q.push(make_tuple(nx,ny,z));
          dist[nx][ny][z] = dist[x][y][z]+1;
        }
        else if(a[nx][ny]==1&&z==1&&dist[nx][ny][z-1]==-1) {
          q.push(make_tuple(nx,ny,z-1));
          dist[nx][ny][z-1] = dist[x][y][z]+1;
        }
      }
    }
  }
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
      a[i][j] = temp[j]-'0';
    }
  }
  bfs();
  if(dist[n-1][m-1][0]==-1&&dist[n-1][m-1][1]==-1) {
    cout << -1 << '\n';
  } else if(dist[n-1][m-1][0]==-1) {
    cout << dist[n-1][m-1][1] << '\n';
  } else if(dist[n-1][m-1][1]==-1) {
    cout << dist[n-1][m-1][0] << '\n';
  } else {
    cout << min(dist[n-1][m-1][0],dist[n-1][m-1][1]) << '\n';
  }
  return 0;
}
