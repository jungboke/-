// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     string a;
//     cin >> a;
//     string b = "quack";
//     int cnt = 0;
//     bool flag = true;
//     while(a.size()!=0)
//     {
//         int k = 0;
//         int how = 0;
//         for(int i=0;i<a.size();i++)
//         {
//             if(a[i]==b[k])
//             {
//                 a.erase(a.begin()+i);
//                 k++;
//                 i--;
//             }
//             if(k==b.size())
//             {
//                 how++;
//                 k = 0;
//             }
//         }
//         if(k!=0)
//         {
//             flag = false;
//             break;
//         }
//         else
//         {
//             if(how==0)
//             {
//                 flag = false;
//                 break;
//             }
//             else cnt++;
//         }
//     }
//     if(flag==false) cout << -1 << '\n';
//     else cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  string crying = "quack";
  int cnt = 0;
  while(a.size()!=0) {
    int idx = 0;
    bool flag = false;
    for(int i=0;i<a.size();i++) {
      if(a[i]==crying[idx]) {
        flag = true;
        idx+=1;
        if(idx==5) idx = 0;
        a.erase(a.begin()+i);
        i-=1;
      }
    }
    if(idx!=0||flag==false) {
      cnt = -1;
      break;
    } else cnt+=1;
  }
  cout << cnt << '\n';
  return 0;
}
