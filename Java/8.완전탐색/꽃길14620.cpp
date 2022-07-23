/*
    next_permutation으로 완전탐색해서 풀었는데 ,dfs로도 문제해결 가능할듯.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int dx[] = {0,-1,0,1,0};
// int dy[] = {0,0,1,0,-1};
// int check(vector<pair<int,int>> a,vector<vector<int>> ary_a)
// {
//     int n = ary_a.size();
//     vector<vector<int>> board(n,vector<int>(n,0));
//     int sum = 0;
//     for(int i=0;i<a.size();i++)
//     {
//         int x,y;
//         x = a[i].first;
//         y = a[i].second;
//         for(int i=0;i<5;i++)
//         {
//             int nx = x+dx[i];
//             int ny = y+dy[i];
//             if(nx>=0&&nx<n&&ny>=0&&ny<n&&board[nx][ny]!=1)
//             {
//                 board[nx][ny] = 1;
//                 sum += ary_a[nx][ny];
//             }
//             else return -1;
//         }
//     }
//     return sum;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n,vector<int>(n,0));
//     vector<pair<int,int>> b;
//     vector<int> result;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//             b.push_back(make_pair(i,j));
//         }
//     }
//     vector<int> perm;
//     for(int i=0;i<3;i++) perm.push_back(1);
//     for(int i=0;i<n*n-3;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     do
//     {
//         vector<pair<int,int>> temp;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1) temp.push_back(b[i]);
//         }
//         int k = check(temp,a);
//         if(k!=-1) result.push_back(k);
//     }while(next_permutation(perm.begin(),perm.end()));
//     cout << *min_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[11][11];
bool check[11][11];
vector<int> result;
int N;

void go(int cnt) {
  if(cnt==3) {
    int sum = 0;
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        if(check[i][j]==true) sum+=a[i][j];
      }
    }
    result.push_back(sum);
    return;
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      if(check[i][j]==true) continue;
      bool flag = true;
      for(int k=0;k<4;k++) {
        int nx = i+dx[k];
        int ny = j+dy[k];
        if(!(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false)) {
          flag = false;
          break;
        }
      }
      if(flag==true) {
        check[i][j] = true;
        for(int k=0;k<4;k++) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          check[nx][ny] = true;
        }
        go(cnt+1);
        check[i][j] = false;
        for(int k=0;k<4;k++) {
          int nx = i+dx[k];
          int ny = j+dy[k];
          check[nx][ny] = false;
        }
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  go(0);
  cout << *min_element(result.begin(),result.end()) << '\n';
  return 0;
}
