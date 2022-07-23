// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     string a;
//     cin >> a;
//     a += '.';
//     string temp = "";
//     string answer = "";
//     for(int i=0;i<a.size();i++)
//     {
//         if(a[i]=='.')
//         {
//             if(temp.size()%2==1)
//             {
//                 cout << -1 << '\n';
//                 return 0;
//             }
//             else
//             {
//                 int x = temp.size()/4;
//                 for(int i=0;i<x;i++) answer += "AAAA";
//                 x = (temp.size()%4)/2;
//                 for(int i=0;i<x;i++) answer += "BB";
//                 answer += '.';
//                 temp = "";
//             }
//         }
//         else temp += a[i];
//     }
//     answer.erase(answer.end()-1);
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
string answer = "";
bool flag = true;

void go(int num) {
  int x = num/4;
  int y = num%4;
  while(y%2!=0&&x>=0) {
    y+=4;
    x--;
  }
  if(x==-1) flag = false;
  else {
    for(int i=0;i<x;i++) answer += "AAAA";
    for(int i=0;i<(y/2);i++) answer += "BB";
  }

}

int main()
{
  string a;
  cin >> a;
  int cnt = 0;
  for(int i=0;i<a.size();i++) {
    if(a[i]=='.') {
      go(cnt);
      answer += '.';
      cnt = 0;
    } else cnt++;
  }
  
  go(cnt);
  if(flag==false) cout << -1 << '\n';
  else cout << answer << '\n';
  return 0; 
}