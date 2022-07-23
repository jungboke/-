/*
    dfs문에 이중for문 집어넣고 돌리면 시간복잡도 매우커짐. 그러니 이중for문말고 idx/m,idx%m으로 이중for문
    처럼 구현하기. 처음 dfs문이 돌아가는 순간 이중for문이면 처음이 이중for문만큼 시작됨.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool check[10][10];
// vector<int> result;
// int N,M;
// void score(vector<vector<int>> color,vector<vector<int>> a)
// {
//     int total = 0;
//     for(int i=0;i<N;i++)
//     {
//         int sum = 0;
//         for(int j=0;j<M;j++)
//         {
//             if(color[i][j]==0)
//             {
//                 sum = sum*10 + a[i][j];
//             }
//             else
//             {
//                 total += sum;
//                 sum = 0;
//             }
//         }
//         total += sum;
//     }
//     for(int j=0;j<M;j++)
//     {
//         int sum = 0;
//         for(int i=0;i<N;i++)
//         {
//             if(color[i][j]==1)
//             {
//                 sum = sum*10 + a[i][j];
//             }
//             else
//             {
//                 total += sum;
//                 sum = 0;
//             }
//         }
//         total += sum;
//     }
//     result.push_back(total);
// }
// void dfs(vector<vector<int>> color,int idx,vector<vector<int>> a)
// {
//     if(idx==N*M)
//     {
//         score(color,a);
//         return;
//     }
//     int x = idx/M;
//     int y = idx%M;
//     color[x][y] = 0;
//     dfs(color,idx+1,a);
//     color[x][y] = 1;
//     dfs(color,idx+1,a);
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     N=n;M=m;
//     vector<vector<int>> a(n,vector<int>(m,0));
//     vector<vector<int>> color(n,vector<int>(m,0));
//     for(int i=0;i<n;i++)
//     {
//         string temp = "";
//         cin >> temp;
//         for(int j=0;j<m;j++)
//         {
//             a[i][j] = temp[j] - 48; 
//         }
//     }
//     dfs(color,0,a);
//     cout << *max_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
char a[4][4];
bool check[4][4];
int maxi = -1;
int N,M;

void cal(string x) {
  int result = 0;
  vector<vector<int>> temp(N,vector<int>(M,0));
  for(int i=0;i<x.size();i++) {
    temp[i/M][i%M] = x[i]-'0';
  }
  for(int i=0;i<N;i++) {
    string num = "";
    for(int j=0;j<M;j++) {
      if(temp[i][j]==0) {
        if(num!="") result += stoi(num);
        num = "";
      } else num += a[i][j];
    }
    if(num!="") result += stoi(num);
  }
  for(int j=0;j<M;j++) {
    string num = "";
    for(int i=0;i<N;i++) {
      if(temp[i][j]==1) {
        if(num!="") result += stoi(num);
        num = "";
      } else num += a[i][j];
    }
    if(num!="") result += stoi(num);
  }
  maxi = max(maxi,result);
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;M=m;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++) {
      a[i][j] = temp[j];
    }
  }
  int k = n*m;
  for(int i=0;i<(1<<k);i++) {
    string temp = "";
    for(int j=0;j<k;j++) {
      if(i&(1<<j)) {
        temp += '1';
      } else temp += '0';
    }
    cal(temp);
  }
  cout << maxi << '\n';
  return 0;
}
