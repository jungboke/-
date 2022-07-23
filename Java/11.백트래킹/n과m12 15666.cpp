/*
    안될거같으면 애초에 for문에서 거르는게 백트래킹이라고 이해.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;
// void dfs(vector<int> a,vector<int> temp,int cnt,int start)
// {
//     if(temp.size()==cnt)
//     {
//         for(int i=0;i<temp.size();i++)
//         {
//             cout << temp[i] << ' ';
//         }
//         cout << '\n';
//         return;
//     }
//     int last = -1;
//     for(int i=start;i<a.size();i++)
//     {
//         if(a[i]!=last)
//         {
//             last = a[i];
//             temp.push_back(a[i]);
//             dfs(a,temp,cnt,i);
//             temp.pop_back();
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
//     dfs(a,temp,m,0);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
set<vector<int>> s;

void dfs(vector<int> temp, int start, int m) {
  if(temp.size()==m) {
    s.insert(temp);
    return;
  }
  for(int i=start;i<a.size();i++) {
    temp.push_back(a[i]);
    dfs(temp,i,m);
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
  dfs(temp,0,m);
  for(auto k:s) {
    for(int i=0;i<k.size();i++) {
      cout << k[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
