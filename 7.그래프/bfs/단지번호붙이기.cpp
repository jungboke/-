// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <tuple>
// #include <string>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// bool check[30][30];
// int main(){

//     int n;
//     cin >> n;
//     vector<vector<int>> a(n,vector<int>(n,0));
//     vector<int> result;
//     for(int i=0;i<n;i++)
//     {
//         string temp = "";
//         cin >> temp;
//         for(int j=0;j<n;j++)
//         {
//             a[i][j] = temp[j] - 48;
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(a[i][j] != 0 && check[i][j] == false)
//             {
//                 int count = 0;
//                 queue<pair<int,int>> q;
//                 q.push(make_pair(i,j));
//                 check[i][j] = true;
//                 while(!q.empty())
//                 {
//                     int x,y;
//                     tie(x,y) = q.front();
//                     q.pop();
//                     count++;
//                     for(int i=0;i<4;i++)
//                     {
//                         int nx = x + dx[i];
//                         int ny = y + dy[i];
//                         if(nx>=0&&nx<n&&ny>=0&&ny<n&&check[nx][ny]==false)
//                         {
//                             if(a[nx][ny] == a[x][y])
//                             {
//                                 q.push(make_pair(nx,ny));
//                                 check[nx][ny] = true;
//                             }
//                         }
//                     } 
//                 }
//                 result.push_back(count);
//             }
//         }
//     }
//     cout << result.size() << '\n';
//     sort(result.begin(),result.end());
//     for(int i=0;i<result.size();i++)
//     {
//         cout << result[i] << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
bool check[26][26];
int a[26][26];
vector<int> answer;
int N;

int bfs(int x, int y) {
  int cnt = 0;
  queue<pair<int,int>> q;
  q.push(make_pair(x,y));
  check[x][y] = true;
  while(!q.empty()) {
    int x,y;
    tie(x,y) = q.front();
    q.pop();
    cnt++;
    for(int i=0;i<4;i++) {
      int nx = x+dx[i];
      int ny = y+dy[i];
      if(nx>=0&&nx<N&&ny>=0&&ny<N) {
        if(check[nx][ny]==false&&a[nx][ny]==1) {
          q.push(make_pair(nx,ny));
          check[nx][ny] = true;
        }
      }
    }
  }
  
  return cnt;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<n;j++) {
      a[i][j] = temp[j]-48;
    }
  }
  int color = 0;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(check[i][j]==false&&a[i][j]==1) {
        int cnt = bfs(i,j);
        answer.push_back(cnt);
        color++;
      }
    }
  }
  cout << color << '\n';
  sort(answer.begin(),answer.end());
  for(int i=0;i<answer.size();i++) {
    cout << answer[i] << '\n';
  }
  return 0;
}