// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// void dfs(vector<int> a,vector<int> temp,int cnt)
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
//     for(int i=0;i<a.size();i++)
//     {
//         temp.push_back(a[i]);
//         dfs(a,temp,cnt);
//         temp.pop_back();
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
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

void dfs(vector<int> temp, int m) {
  if(temp.size()==m) {
    for(int i=0;i<temp.size();i++) {
      cout << temp[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=0;i<a.size();i++) {
    temp.push_back(a[i]);
    dfs(temp,m);
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
  return 0;
}