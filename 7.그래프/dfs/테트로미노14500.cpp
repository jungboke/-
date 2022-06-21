/*
    배열내 특정모형의 이동은 시뮬레이션으로 구현하기는 좀 번거롭고, 특정모형내 칸하나를 기준으로 매칸마다 모형이 완성
    될수 있는지를 가지고 구현하는것이 편할듯, [100][100]단위의 vector배열은 그냥 전역배열로 선언해야 시간초과 안발생.
    dfs함수의 check배열 체크하는 부분 잘 익히기.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// vector<int> result;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int N,M;
// int a[501][501];
// bool check[501][501];
// void dfs(int x,int y,int cnt,int sum)
// {
//     if(cnt==4)
//     {
//         result.push_back(sum);
//         return;
//     }
//     check[x][y] = true;
//     for(int i=0;i<4;i++)
//     {
//         int nx = x+dx[i];
//         int ny = y+dy[i];
//         if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false)
//         {
//             dfs(nx,ny,cnt+1,sum+a[nx][ny]);
//         }
//     }
//     check[x][y] = false;
// }
// void case1(int x,int y)
// {
//     //ㅏ
//     if(x+2<N&&y+1<M)
//     {
//         int sum = a[x][y]+a[x+1][y]+a[x+2][y]+a[x+1][y+1];
//         result.push_back(sum);
//     }
//     //ㅓ
//     if(x+2<N&&y-1>=0)
//     {
//         int sum = a[x][y]+a[x+1][y]+a[x+2][y]+a[x+1][y-1];
//         result.push_back(sum);
//     }
//     //ㅜ
//     if(y+2<M&&x+1<N)
//     {
//         int sum = a[x][y]+a[x][y+1]+a[x][y+2]+a[x+1][y+1];
//         result.push_back(sum);
//     }
//     //ㅗ
//     if(y+2<M&&x-1>=0)
//     {
//         int sum = a[x][y]+a[x][y+1]+a[x][y+2]+a[x-1][y+1];
//         result.push_back(sum);
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     N=n;M=m;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             dfs(i,j,1,a[i][j]);
//             case1(i,j);
//         }
//     }
//     cout << *max_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[501][501];
bool check[501][501];
int maxi = -1;
int N,M;

void cal(int x, int y, int cnt, int sum) {
  if(cnt==4) {
    maxi = max(maxi,sum);
    return;
  }
  for(int i=0;i<4;i++) {
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx>=0&&nx<N&&ny>=0&&ny<M&&check[nx][ny]==false) {
      check[nx][ny] = true;
      cal(nx,ny,cnt+1,sum+a[nx][ny]);
      check[nx][ny] = false;
    }
  }
}

void cal2(int x, int y) {
  if(x-2>=0&&y+1<M) {
    int sum = a[x][y]+a[x-1][y]+a[x-2][y]+a[x-1][y+1];
    maxi = max(maxi,sum);
  }
  if(y+2<M&&x+1<N) {
    int sum = a[x][y]+a[x][y+1]+a[x][y+2]+a[x+1][y+1];
    maxi = max(maxi,sum);
  }
  if(x+2<N&&y-1>=0) {
    int sum = a[x][y]+a[x+1][y]+a[x+2][y]+a[x+1][y-1];
    maxi = max(maxi,sum);
  }
  if(y-2>=0&&x-1>=0) {
    int sum = a[x][y]+a[x][y-1]+a[x][y-2]+a[x-1][y-1];
    maxi = max(maxi,sum);
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
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      check[i][j] = true;
      cal(i,j,1,a[i][j]);
      check[i][j] = false;
      cal2(i,j);
    }
  }
  cout << maxi << '\n';
  return 0;
}