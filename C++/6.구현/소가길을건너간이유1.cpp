// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     map<int,int> m;
//     int cnt = 0;
//     for(int i=0;i<n;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         if(m[x]==0) m[x] = y+1;
//         else
//         {
//             if(m[x]!=y+1)
//             {
//                 m[x] = y+1;
//                 cnt++;
//             }
//         }
//     }
//     cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[100];
int answer = 0;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  memset(a,-1,sizeof(a));
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    if(a[x]!=-1&&a[x]!=y) {
      answer += 1;
    }
    a[x] = y;
  }

  cout << answer << '\n';
  return 0;
}
