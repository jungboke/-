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
//     vector<int> a;
//     for(int i=1;i<=n;i++)
//     {
//         a.push_back(i);
//     }
//     vector<int> temp;
//     dfs(a,temp,m);
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool check[10];
void dfs(vector<int> temp, int n, int m) {
  if(temp.size()==m) {
    for(int i=0;i<temp.size();i++) {
      cout << temp[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=1;i<=n;i++) {
    temp.push_back(i);
    dfs(temp,n,m);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  vector<int> temp;
  dfs(temp,n,m);
  return 0;
}
