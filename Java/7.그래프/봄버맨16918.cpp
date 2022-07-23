/*
  3초가 지난 폭탄을 터뜨리는 과정에서 2차원 순차탐색으로
  터뜨리면 터뜨리는 과정에서 다른 폭탄이 유실되어 결과값이 달라짐.
  따라서 함수내에 임시2차원 배열 설정후, 폭탄을 터뜨리는 과정을
  가상화한 뒤, 마지막에 해당 배열을 진짜 배열에 대입함.

  시간단위로 진행되는 시뮬레이션은 시간 카운트를 while(true) 문
  맨 마지막이 아닌 맨 앞에서 먼저 해주면 생각하기 편함.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <string.h>
// #include <queue>
// #include <tuple>
// using namespace std;
// int dx[] = {-1,0,1,0};
// int dy[] = {0,1,0,-1};
// int dist[201][201];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     memset(dist,-1,sizeof(dist));
//     int n,m,k;
//     cin >> n >> m >> k;
//     vector<vector<char>> a(n,vector<char>(m,'0'));
//     for(int i=0;i<n;i++)
//     {
//         string temp = "";
//         cin >> temp;
//         for(int j=0;j<m;j++)
//         {
//             a[i][j] = temp[j];
//             if(a[i][j]=='O') dist[i][j] = 1;
//         }
//     }
//     int cnt = 1; 
//     while(cnt<k)
//     {
//         cnt++;
//         queue<pair<int,int>> q;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 dist[i][j]++;
//                 if(dist[i][j]==3)
//                 {
//                     dist[i][j] = -1;
//                     q.push(make_pair(i,j));
//                 }
//             }
//         }
//         while(!q.empty())
//         {
//             int x,y;
//             tie(x,y) = q.front();
//             q.pop();
//             for(int i=0;i<4;i++)
//             {
//                 int nx = x+dx[i];
//                 int ny = y+dy[i];
//                 if(nx>=0&&nx<n&&ny>=0&&ny<m)
//                 {
//                     dist[nx][ny] = -1;    
//                 }
//             }
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(dist[i][j]==-1) cout << '.';
//             else cout << 'O';
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define time _time
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
char a[201][201];
int time[201][201];
int N,M,K;

void bomb() {
  char tmp_a[N][M];
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      tmp_a[i][j] = a[i][j]; 
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(time[i][j]==3&&a[i][j]=='O') {
        tmp_a[i][j] = '.';
        for(int k=0;k<4;k++) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          if(nx>=0&&nx<N&&ny>=0&&ny<M) {
            tmp_a[nx][ny] = '.';
          }
        }
      }
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      a[i][j] = tmp_a[i][j];
    }
  }
}

void cnt_bomb() {
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(a[i][j]=='O') time[i][j]+=1;
    }
  }
  bomb();
}

void set_bomb() {
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(a[i][j]=='.') {
        a[i][j] = 'O';
        time[i][j] = 0;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int n,m,k;
  cin >> n >> m >> k;
  N=n;M=m;K=k;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++) {
      a[i][j] = temp[j];
    }
  }
  int cnt = 0;
  while(true) {
    cnt++;
    cnt_bomb();
    if(cnt!=1&&cnt%2==0) set_bomb();
    if(cnt==k) break;
  }

  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout << a[i][j];
    }
    cout << '\n';
  }
  return 0;
}
