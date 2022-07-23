// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <string.h>
// #include <tuple>
// using namespace std;
// int dx[] = {0,-1,0,1};
// int dy[] = {-1,0,1,0};
// int a[1001][1001];
// int dist[1001][1001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     int sx,sy;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j]==2)
//             {
//                 a[i][j] = 0;
//                 sx = i;
//                 sy = j;
//             }
//         }
//     }
//     memset(dist,-1,sizeof(dist));
//     queue<pair<int,int>> q;
//     q.push(make_pair(sx,sy));
//     dist[sx][sy] = 0;
//     while(!q.empty())
//     {
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==-1)
//             {
//                 if(a[nx][ny]==1)
//                 {
//                     q.push(make_pair(nx,ny));
//                     dist[nx][ny] = dist[x][y]+1;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(dist[i][j]==-1)
//             {
//                 if(a[i][j]==0) dist[i][j] = 0;
//                 else if(a[i][j]==1) dist[i][j] = -1;
//             }
//             cout << dist[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[1001][1001];
int dist[1001][1001];

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  memset(dist,-1,sizeof(dist));
  queue<pair<int,int>> q;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
      if(a[i][j]==2) {
        q.push(make_pair(i,j));
        dist[i][j] = 0;
      }
    }
  }
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==-1) {
        if(a[nx][ny]==1) {
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y]+1;
        }
      }
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      if(dist[i][j]==-1) {
        if(a[i][j]==0) dist[i][j] = 0;
        else if(a[i][j]==1) dist[i][j] = -1;
      }
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
