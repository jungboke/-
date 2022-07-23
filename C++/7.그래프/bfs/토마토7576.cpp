// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <string.h>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int dist[1001][1001];
// int main(){

//     memset(dist,-1,sizeof(dist));
//     int n,m;
//     cin >> m >> n;
//     vector<vector<int>> a(n,vector<int>(m,0));
//     vector<pair<int,int>> result;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j] == 1)
//             {
//                 result.push_back(make_pair(i,j));
//             }
//             else if(a[i][j] == -1)
//             {
//                 dist[i][j] = 0;
//             }
//         }
//     }
//     queue<pair<int,int>> q;
//     for(int i=0;i<result.size();i++)
//     {
//         auto pair = result[i];
//         q.push(pair);
//         dist[pair.first][pair.second] = 0;
//     }
//     while(!q.empty())
//     {
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==-1&&a[nx][ny]!=-1)
//             {
//                 q.push(make_pair(nx,ny));
//                 dist[nx][ny] = dist[x][y]+1;
//             }
//         }
//     }
//     int maxi = 0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(dist[i][j] == -1)
//             {
//                 cout << -1 << '\n';
//                 return 0;
//             }
//             if(maxi<dist[i][j]) maxi = dist[i][j];
//         }
//     }
//     cout << maxi << '\n';
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
  int m,n;
  cin >> m >> n;
  queue<pair<int,int>> q;
  memset(dist,-1,sizeof(dist));
  int zero_flag = false;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
      if(a[i][j]==1) {
        q.push(make_pair(i,j));
        dist[i][j] = 0;
      } else if(a[i][j]==0) {
        zero_flag = true;
      }
    }
  }
  if(zero_flag==false) {
    cout << 0 << '\n';
    return 0;
  }
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<n&&ny>=0&&ny<m) {
        if(dist[nx][ny]==-1&&a[nx][ny]==0) {
          q.push(make_pair(nx,ny));
          dist[nx][ny] = dist[x][y]+1;
        }
      }
    }
  }
  bool flag = true;
  int maxi = -1;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      maxi = max(maxi,dist[i][j]);
      if(dist[i][j]==-1&&a[i][j]==0) flag = false;
    }
  }
  
  if(flag==false) cout << -1 << '\n';
  else cout << maxi << '\n';
  return 0;
}
