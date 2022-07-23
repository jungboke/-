// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<string> a(n);
//     for(int i=0;i<n;i++)
//     {
//         string temp = "";
//         cin >> temp;
//         a[i] = temp;
//     }
//     string result = "";
//     int cnt = 0;
//     for(int i=0;i<m;i++)
//     {
//         map<char,int> map1;
//         for(int j=0;j<n;j++)
//         {
//             map1[a[j][i]]++;
//         }
//         int maxi = 0;
//         char alp;
//         for(auto k : map1)
//         {
//             if(k.second>maxi)
//             {
//                 maxi = k.second;
//                 alp = k.first;
//             }
//         }
//         result += alp;
//         cnt += (n-maxi);
//     }
//     cout << result << '\n';
//     cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<string> a(1001);

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  string answer = "";
  int ans_sum = 0;
  for(int i=0;i<m;i++) {
    map<char,int> map1;
    for(int j=0;j<n;j++) {
      map1[a[j][i]]++;
    }
    int maxi = -1;
    char max_alp;
    for(auto k:map1) {
      if(maxi<k.second) {
        maxi = k.second;
        max_alp = k.first;
      }  
    }
    answer += max_alp;
    ans_sum += (n-maxi);
  }
  cout << answer << '\n';
  cout << ans_sum << '\n';
  return 0;
}