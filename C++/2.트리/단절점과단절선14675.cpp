/*
    또 어려워보이는 문제 쉬운 아이디어 파악못해서 틀림. 트리의 경우 단절선과 단절점 파악이 쉽다는 점을
    생각해야했음. 제발 어려워보이면 푸는 알고리즘보다 아이디어부터 생각하기.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// vector<int> a[100001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     int m;
//     cin >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         if(x==1)
//         {
//             if(a[y].size()>=2)
//             {
//                 cout << "yes" << '\n';
//             }
//             else cout << "no" << '\n';
//         }
//         else if(x==2)
//         {
//             cout << "yes" << '\n';
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[100001];

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
  int m;
  cin >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    if(x==1) {
      if(a[y].size()==1) cout << "no" << '\n';
      else cout << "yes" << '\n';
    } else cout << "yes" << '\n';
  }
  return 0;
}
