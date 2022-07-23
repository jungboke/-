/*
  굳이 매 연합마다 번호를 붙이고, 해당 번호마다 전체 배열 search후,
  값 계산하는 것 보다 연합을 찾을 때마다 값 계산을 해주는 게 효율적임.
*/
// #include <bits/stdc++.h>
// using namespace std;
// int dx[] = {0,-1,0,1};
// int dy[] = {-1,0,1,0};
// int a[51][51];
// bool check[51][51];
// int N,L,R;
// int bfs(int x,int y)
// {
//     vector<pair<int,int>> temp;
//     int sum = 0;
//     queue<pair<int,int>> q;
//     q.push(make_pair(x,y));
//     temp.push_back(make_pair(x,y));
//     sum += a[x][y];
//     check[x][y] = true;
//     while(!q.empty())
//     {
//         int x,y;
//         tie(x,y) = q.front();
//         q.pop();
//         for(int i=0;i<4;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false)
//             {
//                 int num1 = abs(a[nx][ny]-a[x][y]);
//                 if(num1>=L&&num1<=R)
//                 {
//                     q.push(make_pair(nx,ny));
//                     check[nx][ny] = true;
//                     temp.push_back(make_pair(nx,ny));
//                     sum += a[nx][ny];
//                 }
//             }
//         }
//     }
//     if(temp.size()!=1)
//     {
//         sum /= temp.size();
//         for(int i=0;i<temp.size();i++)
//         {
//             a[temp[i].first][temp[i].second] = sum;
//         }
//     }
//     return temp.size();
// }
// int main()
// {
//     int n,l,r;
//     cin >> n >> l >> r;
//     N=n;L=l;R=r;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     int day = 0;
//     bool flag = true;
//     while(flag==true)
//     {
//         memset(check,false,sizeof(check));
//         flag = false;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(check[i][j]==false)
//                 {
//                     int x = bfs(i,j);
//                     if(x!=1)
//                     {
//                         flag = true;
//                     }
//                 }
//             }
//         }
//         if(flag==false) break;
//         day++;
//     }
//     cout << day << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[51][51];
bool check[51][51];
int N,L,R;

int a_open() {
  int cnt = 1;
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(check[i][j]==false) {
        queue<pair<int,int>> q;
        vector<pair<int,int>> temp;
        int sum = 0;
        q.push(make_pair(i,j));
        check[i][j] = true;
        temp.push_back(make_pair(i,j));
        sum += a[i][j];
        while(!q.empty()) {
          int x,y;
          tie(x,y) = q.front();
          q.pop();
          for(int k=0;k<4;k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false) {
              int diff = abs(a[nx][ny]-a[x][y]);
              if(diff>=L&&diff<=R) {
                q.push(make_pair(nx,ny));
                check[nx][ny] = true;
                temp.push_back(make_pair(nx,ny));
                sum += a[nx][ny];
              }
            }
          }
        }
        for(int i=0;i<temp.size();i++) {
          int x,y;
          tie(x,y) = temp[i];
          a[x][y] = sum/temp.size();
        }
        cnt+=1;
      }
    }
  }

  return cnt-1;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,l,r;
  cin >> n >> l >> r;
  N=n;L=l;R=r;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  int day = -1;
  while(true) {
    memset(check,false,sizeof(check));
    day++;
    int cnt = a_open();
    if(cnt==pow(n,2)) break;
  }

  cout << day << '\n';
  return 0;
}