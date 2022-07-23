// cin.eof()를 통해 eof()값 받았는지 확인.
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        int idx = 0;
        bool flag = false;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==a[idx]) idx++;
            if(idx>=a.size())
            {
                flag = true;
                break;
            }   
        }
        if(flag==true) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     while(true)
//     {
//         string a,b;
//         cin >> a >> b;
//         if(cin.eof()) break;
//         int idx = 0;
//         bool flag = false;
//         for(int i=0;i<b.size();i++)
//         {
//             if(b[i]==a[idx])
//             {
//                 idx++;
//                 if(idx>=a.size())
//                 {
//                     flag = true;
//                     break;
//                 }
//             }
//         }
//         if(flag==true) cout << "Yes" << '\n';
//         else cout << "No" << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  while(true) {
    string s,t;
    cin >> s >> t;
    if(cin.eof()) break;
    string temp = "";
    int idx = 0;
    for(int i=0;i<t.size();i++) {
      if(t[i]==s[idx]) {
        temp += t[i];
        idx+=1;
      }
    }
    if(temp.size()!=s.size()) cout << "No" << '\n';
    else cout << "Yes" << '\n';
  }
  return 0;
}
