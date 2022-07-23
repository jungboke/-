/*
    범위체크할때 누적합개념을 사용해서 시간단축하기.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[1001][1001];
int dist[1001][1001];
bool reccheck(int x,int y,int h,int w,int dir)
{
    bool flag = true;
    if(dir==0)
    {
        for(int i=x;i<x+h;i++)
        {
            if(a[i][y]==1)
            {
                flag = false;
                break;
            }
        }
    }
    else if(dir==1)
    {
        for(int j=y;j<y+w;j++)
        {
            if(a[x][j]==1)
            {
                flag = false;
                break;
            }
        }
    }
    else if(dir==2)
    {
        for(int i=x;i<x+h;i++)
        {
            if(a[i][y+w-1]==1)
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        for(int j=y;j<y+w;j++)
        {
            if(a[x+h-1][j]==1)
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist,-1,sizeof(dist));
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int h,w,sx,sy,fx,fy;
    cin >> h >> w >> sx >> sy >> fx >> fy;
    sx-=1;sy-=1;fx-=1;fy-=1;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    dist[sx][sy] = 0;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx+h-1<n&&ny>=0&&ny+w-1<m&&dist[nx][ny]==-1)
            {
                if(reccheck(nx,ny,h,w,i)==true)
                {
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
        }
    }
    if(dist[fx][fy]==-1) cout << -1 << '\n';
    else cout << dist[fx][fy] << '\n';
    return 0;
}
*/
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
// bool reccheck(int x,int y,int h,int w,int dir)
// {
//     bool flag = true;
//     if(dir==0)
//     {
//         for(int i=x;i<x+h;i++)
//         {
//             if(a[i][y]==1)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     else if(dir==1)
//     {
//         for(int j=y;j<y+w;j++)
//         {
//             if(a[x][j]==1)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     else if(dir==2)
//     {
//         for(int i=x;i<x+h;i++)
//         {
//             if(a[i][y+w-1]==1)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     else if(dir==3)
//     {
//         for(int j=y;j<y+w;j++)
//         {
//             if(a[x+h-1][j]==1)
//             {
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     return flag;
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     int h,w,sx,sy,fx,fy;
//     cin >> h >> w >> sx >> sy >> fx >> fy;
//     sx-=1;sy-=1;fx-=1;fy-=1;
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
//             if(nx>=0&&nx<n-h+1&&ny>=0&&ny<m-w+1&&dist[nx][ny]==-1)
//             {
//                 if(reccheck(nx,ny,h,w,i)==true)
//                 {
//                     q.push(make_pair(nx,ny));
//                     dist[nx][ny] = dist[x][y]+1;
//                 }
//             }
//         }
//     }
//     if(dist[fx][fy]==-1) cout << -1 << '\n';
//     else cout << dist[fx][fy] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[1001][1001];
int dist[1001][1001];
int N,M;
void bfs(int low, int col, int x, int y) {
  memset(dist,-1,sizeof(dist));
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  dist[x][y] = 0;
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    if(y+col<M&&dist[x][y+1]==-1) {
      bool flag = true;
      for(int i=x;i<x+low;i++) {
        if(a[i][y+col]==1) flag = false; 
      }
      if(flag==true) {
        q.push(make_pair(x,y+1));
        dist[x][y+1] = dist[x][y]+1;
      }
    }
    if(x+low<N&&dist[x+1][y]==-1) {
      bool flag = true;
      for(int j=y;j<y+col;j++) {
        if(a[x+low][j]==1) flag = false; 
      }
      if(flag==true) {
        q.push(make_pair(x+1,y));
        dist[x+1][y] = dist[x][y]+1;
      }
    }
    if(y-1>=0&&dist[x][y-1]==-1) {
      bool flag = true;
      for(int i=x;i<x+low;i++) {
        if(a[i][y-1]==1) flag = false; 
      }
      if(flag==true) {
        q.push(make_pair(x,y-1));
        dist[x][y-1] = dist[x][y]+1;
      }
    }
    if(x-1>=0&&dist[x-1][y]==-1) {
      bool flag = true;
      for(int j=y;j<y+col;j++) {
        if(a[x-1][j]==1) flag = false; 
      }
      if(flag==true) {
        q.push(make_pair(x-1,y));
        dist[x-1][y] = dist[x][y]+1;
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
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  int low,col,sx,sy,ex,ey;
  cin >> low >> col >> sx >> sy >> ex >> ey;
  bfs(low,col,sx-1,sy-1);
  cout << dist[ex-1][ey-1] << '\n';
  return 0;
}