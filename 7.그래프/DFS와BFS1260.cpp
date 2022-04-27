// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <string.h>
// #include <queue>
// using namespace std;
// vector<int> a[1001];
// bool check[1001];
// void dfs(int num,vector<int> &answer)
// {
//     check[num] = true;
//     answer.push_back(num);
//     for(auto k : a[num])
//     {
//         if(check[k]==false) dfs(k,answer);
//     }
// }
// void bfs(int num,vector<int> &answer)
// {
//     queue<int> q;
//     q.push(num);
//     check[num] = true;
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         answer.push_back(x);
//         for(auto k : a[x])
//         {
//             if(check[k]==false)
//             {
//                 q.push(k);
//                 check[k] = true;
//             }
//         }
//     }
// }
// int main()
// {
//     int n,m,k;
//     cin >> n >> m >> k;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     for(int i=1;i<=n;i++)
//     {
//         sort(a[i].begin(),a[i].end());
//     }
//     vector<int> answer1;
//     vector<int> answer2;
//     dfs(k,answer1);
//     memset(check,false,sizeof(check));
//     bfs(k,answer2);
//     for(int i=0;i<answer1.size();i++)
//     {
//         cout << answer1[i] << ' ';
//     }
//     cout << '\n';
//     for(int i=0;i<answer2.size();i++)
//     {
//         cout << answer2[i] << ' ';
//     }
//     cout << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[1001];
bool check[1001];

void dfs(int x) {
  check[x] = true;
  cout << x << ' ';
  for(auto k:a[x]) {
    if(check[k]==false) {
      dfs(k);
    }
  }
}

void bfs(int x) {
  queue<int> q;
  q.push(x);
  check[x] = true;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    cout << x << ' ';
    for(auto k:a[x]) {
      if(check[k]==false) {
        q.push(k);
        check[k] = true;
      }
    }
  }
}

int main(int argc, char const *argv[])
{
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  for(int i=1;i<=n;i++) {
    sort(a[i].begin(),a[i].end());
  }
  dfs(k);
  cout << '\n';
  memset(check,false,sizeof(check));
  bfs(k);
  return 0;
}