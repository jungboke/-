/*
 비가 전체내린후에 물복사버그를 진행하는것과 비가 내리는 도중 물복사 버그를 진행시키는 것이
 다른것처럼 진행순서 잘확인하기!
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int dx[] = {0,-1,-1,-1,0,1,1,1};
// int dy[] = {-1,-1,0,1,1,1,0,-1};
// void move(vector<vector<int>> &b,int num,int how)
// {
//     int n = b.size();
//     vector<vector<int>> tmp_b(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(b[i][j]==1)
//             {
//                 int nx = i+dx[num]*how;
//                 int ny = j+dy[num]*how;
//                 while(nx<0) nx+=n;
//                 while(nx>=n) nx-=n;
//                 while(ny<0) ny+=n;
//                 while(ny>=n) ny-=n;
//                 tmp_b[nx][ny] = 1;
                
//             }
//         }
//     }
//     b = tmp_b;
// }
// void rain(vector<vector<int>> &a,vector<vector<int>> b)
// {
//     int n = a.size();
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(b[i][j]==1) a[i][j]++;
//             else continue;
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(b[i][j]==1)
//             {
//                 for(int k=1;k<8;k+=2)
//                 {
//                     int ux = i+dx[k];
//                     int uy = j+dy[k];
//                     if(ux>=0&&ux<n&&uy>=0&&uy<n)
//                     {
//                         if(a[ux][uy]>0) a[i][j]++;
//                     }
//                 }
//             }
//         }
//     }
// }
// void make(vector<vector<int>> &a,vector<vector<int>> &b)
// {
//     int n = a.size();
//     vector<vector<int>> tmp_b(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             if(a[i][j]>=2&&b[i][j]!=1)
//             {
//                 tmp_b[i][j] = 1;
//                 a[i][j] -= 2;
//             }
//         }
//     }
//     b = tmp_b;
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> a(n,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     vector<vector<int>> b(n,vector<int>(n,0));
//     b[n-2][0] = 1; b[n-2][1] = 1; b[n-1][0] = 1; b[n-1][1] = 1;
//     for(int i=0;i<m;i++)
//     {
//         int num,how;
//         cin >> num >> how;
//         num-=1;
//         move(b,num,how);
//         rain(a,b);
//         make(a,b);
//     }
//     int sum = 0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             sum += a[i][j];
//         }
//     }
//     cout << sum << '\n';   
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
int ddx[] = {-1,-1,1,1};
int ddy[] = {-1,1,1,-1};
int a[51][51];
int c[51][51];
int N;

void move(int d, int s) {
  int tmp_c[N][N];
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      tmp_c[i][j] = 0;
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(c[i][j]==1) {
        int ni = i+dx[d]*s;
        int nj = j+dy[d]*s;
        while(ni<0) ni+=N;
        while(ni>=N) ni-=N;
        while(nj<0) nj+=N;
        while(nj>=N) nj-=N;
        tmp_c[ni][nj] = 1;
      }
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      c[i][j] = tmp_c[i][j];
    }
  }
}

void rain_down() {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(c[i][j]==1) a[i][j] += 1;
    }
  }
}

void copy() {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(c[i][j]==1) {
        int cnt = 0;
        for(int k=0;k<4;k++) {
          int ni = i+ddx[k];
          int nj = j+ddy[k];
          if(ni>=0&&ni<N&&nj>=0&&nj<N) {
            if(a[ni][nj]>0) cnt+=1;
          }
        }
        a[i][j]+=cnt;
      }
    }
  }
}

void rain_up() {
  int tmp_c[N][N];
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      tmp_c[i][j] = 0;
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(a[i][j]>=2&&c[i][j]!=1) {
        tmp_c[i][j] = 1;
        a[i][j]-=2;
      }
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      c[i][j] = tmp_c[i][j];
    }
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  c[n-1][0] = 1;
  c[n-1][1] = 1;
  c[n-2][0] = 1;
  c[n-2][1] = 1;
  for(int i=0;i<m;i++) {
    int d,s;
    cin >> d >> s;
    move(d-1,s);
    rain_down();
    copy();
    rain_up();
  }
  int answer = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      answer += a[i][j];
    }
  }

  cout << answer << '\n';
  return 0;
}