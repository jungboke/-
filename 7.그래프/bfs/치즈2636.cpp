/*
    bfs함수화 적용, 공기중을 2로 표현하기위해서 bfs적용, 시뮬레이션 적용, 최대한 반복되는 부분 함수화했음.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check1[101][101];
void bfs(vector<vector<int>> &a)
{
    memset(check1,false,sizeof(check1));
    int n = a.size();
    int m = a[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check1[0][0] = true;
    a[0][0] = 2;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&check1[nx][ny]==false)
            {
                if(a[nx][ny]==0)
                {
                    q.push(make_pair(nx,ny));
                    check1[nx][ny] = true;
                    a[nx][ny] = 2;
                }
            }
        }
    }
}
bool check(vector<vector<int>> a,int x,int y)
{
    int n = a.size();
    int m = a[0].size();
    bool flag = false;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
        {
            if(a[nx][ny]==2)
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}
int checksize(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1) cnt++;
        }
    }
    return cnt;
}
void change(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a = a;
    bfs(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                if(check(a,i,j)==true)
                {
                    tmp_a[i][j] = 0;
                }
            }
        }
    }
    a = tmp_a;
} 
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int last = 0;
    while(true)
    {
        if(checksize(a)==0) break;
        last = checksize(a);
        change(a);
        cnt++;
    }
    cout << cnt << '\n';
    cout << last << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int dx[] = {0,-1,0,1};
// int dy[] = {-1,0,1,0};
// int a[101][101];
// int check[101][101];
// int N,M;
// void change()
// {
//     queue<pair<int,int>> q;
//     q.push(make_pair(0,0));
//     check[0][0] = true;
//     while(!q.empty())
//     {
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false)
//             {
//                 if(a[nx][ny]==0)
//                 {
//                     q.push(make_pair(nx,ny));
//                     check[nx][ny] = true;
//                 }
//             }
//         }
//     }
// }
// void cheeze()
// {
//     for(int i=0;i<N;i++)
//     {
//         for(int j=0;j<M;j++)
//         {
//             if(a[i][j]==0) continue;
//             for(int k=0;k<4;k++)
//             {
//                 int nx = i+dx[k];
//                 int ny = j+dy[k];
//                 if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==true)
//                 {
//                     a[i][j] = 0;
//                     break;
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     N=n;M=m;
//     int cnt = 0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j]==1) cnt++;
//         }
//     }
//     int day = 0;
//     bool flag = true;
//     while(flag==true)
//     {
//         flag = false;
//         memset(check,false,sizeof(check));
//         change();
//         cheeze();
//         int num = 0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(a[i][j]!=0)
//                 {
//                     flag = true;
//                     num++;
//                 } 
//             }
//         }
//         if(flag==true) cnt = num;
//         day++;
//     }
//     cout << day << '\n';
//     cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[101][101];
bool check[101][101];
int N,M;

pair<int,int> bfs() {
  memset(check,false,sizeof(check));
  queue<pair<int,int>> q;
  q.push(make_pair(0,0));
  check[0][0] = true;
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
        if(a[nx][ny]==0) {
          q.push(make_pair(nx,ny));
          check[nx][ny] = true;
        }  
      }
    }
  }
  int left_cnt = 0;
  int erase_cnt = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(a[i][j]==0) continue;
      bool flag = true;
      for(int k=0;k<4;k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==true) {
          a[i][j] = 0;
          flag = false;
          erase_cnt+=1;
          break;
        }
      }
      if(flag==true) left_cnt+=1;
    }
  }
  return make_pair(erase_cnt,left_cnt);
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
  int t = 0;
  int cnt = 0;
  while(true) {
    t+=1;
    auto p = bfs();
    if(p.second==0) {
      if(p.first==0) t-=1;
      cnt = p.first;
      break;
    }
  }
  cout << t << '\n';
  cout << cnt << '\n';
  return 0;
}
