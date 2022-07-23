// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool check[10];
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
vector<int> a;
bool check[10];

void dfs(int maxi, vector<int> temp) {
  if(temp.size()==maxi) {
    for(int i=0;i<temp.size();i++) {
      cout << temp[i] << ' '; 
    }
    cout << '\n';
    return;
  }
  for(int i=0;i<a.size();i++) {
    if(check[i]==false) {
      check[i] = true;
      temp.push_back(a[i]);
      dfs(maxi,temp);
      temp.pop_back();
      check[i] = false;
    }
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) {
    a.push_back(i);
  }
  vector<int> temp;
  dfs(m,temp);
  return 0;
}
