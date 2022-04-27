/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> a[101];
bool check[101];
void dfs(int num)
{
    check[num] = true;
    for(auto k:a[num])
    {
        if(check[k]==false) dfs(k);
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==true) answer++;
    }
    cout << answer-1 << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// vector<int> a[101];
// bool check[101];
// void dfs(int num)
// {
//     check[num] = true;
//     for(int k : a[num])
//     {
//         if(check[k]==false)
//         {
//             dfs(k);
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     dfs(1);
//     int answer = 0;
//     for(int i=1;i<=n;i++)
//     {
//         if(check[i]==true) answer++;
//     }
//     cout << answer-1 << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[101];
bool check[101];

void dfs(int x) {
  check[x] = true;
  for(auto k:a[x]) {
    if(check[k]==false) {
      dfs(k);
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int m;
  cin >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  dfs(1);
  int answer = 0;
  for(int i=2;i<=n;i++) {
    if(check[i]==true) {
      answer++;
    }
  }

  cout << answer << '\n';
  return 0; 
}






















