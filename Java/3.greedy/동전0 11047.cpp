// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end(),greater<>());
//     int answer = 0;
//     for(int i=0;i<a.size();i++)
//     {
//         if(m/a[i]==0) continue;
//         else
//         {
//             answer += m/a[i];
//             m = m%a[i];
//         }
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(int argc, char const *argv[])
{
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end(),greater<>());
  int answer = 0;
  for(int i=0;i<a.size();i++) {
    int div = k/a[i];
    if(div==0) continue;
    answer += div;
    k = k%a[i];
  }

  cout << answer << '\n';
  return 0;
}
