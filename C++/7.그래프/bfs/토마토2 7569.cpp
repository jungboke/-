//tuple사용을 통한 3차원 구현. + get<0>(personInfo),get<1>(personInfo),get<2>(personInfo)

// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <string.h>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int a[101][101][101];
// int check[101][101][101];
// int main()
// {
//     memset(check,-1,sizeof(check));
//     int n,m,h;
//     cin >> m >> n >> h;
//     queue<tuple<int,int,int>> q;
//     for(int z=0;z<h;z++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 cin >> a[i][j][z];
//                 if(a[i][j][z]==1)
//                 {
//                     q.push(make_tuple(i,j,z));
//                     check[i][j][z] = 0;
//                 }
//                 else if(a[i][j][z]==-1)
//                 {
//                     check[i][j][z] = 0;
//                 }
//             }
//         }
//     }
//     while(!q.empty())
//     {
//         int x,y,z;
//         tie(x,y,z) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny][z]==-1)
//             {
//                 if(a[nx][ny][z]==0)
//                 {
//                     q.push(make_tuple(nx,ny,z));
//                     check[nx][ny][z] = check[x][y][z] + 1;
//                 }
//             }
//         }
//         if(z-1>=0&&check[x][y][z-1]==-1&&a[x][y][z-1]==0)
//         {
//             q.push(make_tuple(x,y,z-1));
//             check[x][y][z-1] = check[x][y][z] + 1;
//         }
//         if(z+1<h&&check[x][y][z+1]==-1&&a[x][y][z+1]==0)
//         {
//             q.push(make_tuple(x,y,z+1));
//             check[x][y][z+1] = check[x][y][z] + 1;
//         }
//     }
//     int cnt = 0;
//     for(int z=0;z<h;z++)
//     {
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(check[i][j][z]==-1)
//                 {
//                     cout << -1 << '\n';
//                     return 0;    
//                 }
//                 if(cnt<check[i][j][z]) cnt = check[i][j][z];
//             }
//         }
//     }
//     cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int dz[] = {-1,1};
int a[101][101][101];
int dist[101][101][101];
int maxi = -1;

int main(int argc, char const *argv[])
{
  int m,n,h;
  cin >> m >> n >> h;
  memset(dist,-1,sizeof(dist));
  queue<tuple<int,int,int>> q;
  bool zero_flag = false;
  for(int c=0;c<h;c++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        cin >> a[c][i][j];
        if(a[c][i][j]==1) {
          q.push(make_tuple(c,i,j));
          dist[c][i][j] = 0;
        } else if(a[c][i][j]==0) zero_flag = true;
      }
    }
  }
  if(zero_flag==false) {
    cout << 0 << '\n';
    return 0;
  }
  while(!q.empty()) {
    int x,y,z;
    tie(z,x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx>=0&&nx<n&&ny>=0&&ny<m) {
        if(dist[z][nx][ny]==-1&&a[z][nx][ny]!=-1) {
          q.push(make_tuple(z,nx,ny));
          dist[z][nx][ny] = dist[z][x][y] + 1;
        }
      }
    }
    for(int i=0;i<2;i++) {
      int nz = z + dz[i];
      if(nz>=0&&nz<h) {
        if(dist[nz][x][y]==-1&&a[nz][x][y]!=-1) {
          q.push(make_tuple(nz,x,y));
          dist[nz][x][y] = dist[z][x][y] + 1;
        }
      }
    }
  }
  bool flag = true;
  for(int c=0;c<h;c++) {
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++) {
        if(a[c][i][j]==0&&dist[c][i][j]==-1) {
          flag = false;
        }
        else maxi = max(maxi,dist[c][i][j]);
      }
    }
  }

  if(flag==false) cout << -1 << '\n';
  else cout << maxi << '\n';
  return 0;
}