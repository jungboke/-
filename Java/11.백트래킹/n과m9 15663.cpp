/*
    set에 vector집어넣을때 순서상관있음.
    set활용안하고 풀어보기.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;
// bool check[10];
// set<vector<int>> result;
// void dfs(vector<int> a,vector<int> temp,int cnt)
// {
//     if(temp.size()==cnt)
//     {
//         result.insert(temp);
//         return;
//     }
//     for(int i=0;i<a.size();i++)
//     {
//         if(check[i]==false)
//         {
//             check[i] = true;
//             temp.push_back(a[i]);
//             dfs(a,temp,cnt);
//             temp.pop_back();
//             check[i] = false;
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     vector<int> temp;
//     dfs(a,temp,m);
//     for(auto k:result)
//     {
//         for(int i=0;i<k.size();i++)
//         {
//             cout << k[i] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
set<vector<int>> s;
bool check[10];

void dfs(vector<int> temp, int m) {
  if(temp.size()==m) {
    s.insert(temp);
    return;
  }
  for(int i=0;i<a.size();i++) {
    if(check[i]==true) continue;
    temp.push_back(a[i]);
    check[i] = true;
    dfs(temp,m);
    check[i] = false;
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  vector<int> temp;
  dfs(temp,m);
  for(auto k:s) {
    for(int i=0;i<k.size();i++) {
      cout << k[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
