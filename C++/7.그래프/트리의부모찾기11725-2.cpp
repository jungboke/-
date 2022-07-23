// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// vector<int> a[100001];
// bool check[100001];
// int parent[100001];
// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     queue<int> q;
//     q.push(1);
//     check[1] = true;
//     parent[1] = -1;
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         for(auto k:a[x])
//         {
//             if(check[k]==false)
//             {
//                 q.push(k);
//                 check[k] = true;
//                 parent[k] = x;
//             }
//         }
//     }
//     for(int i=2;i<=n;i++)
//     {
//         cout << parent[i] << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[100001];
int parent[100001];
bool check[100001];

void dfs(int x) {
  check[x] = true;
  for(auto k:a[x]) {
    if(check[k]==false) {
      parent[k] = x;
      dfs(k);
    }
  }
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n-1;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1);
  for(int i=2;i<=n;i++) {
    cout << parent[i] << '\n';
  }
  return 0;
}
