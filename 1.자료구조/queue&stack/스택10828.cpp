// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <stack>
// using namespace std;

// int main()
// {
//     stack<int> st;
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         string a;
//         cin >> a;
//         if(a=="push")
//         {
//             int b;
//             cin >> b;
//             st.push(b);
//         }
//         else if(a=="pop")
//         {
//             if(!st.empty())
//             {
//                 int x = st.top();
//                 st.pop();
//                 cout << x << '\n';
//             }
//             else cout << -1 << '\n';
//         }
//         else if(a=="size")
//         {
//             cout << st.size() << '\n';
//         }
//         else if(a=="empty")
//         {
//             cout << st.empty() << '\n';
//         }
//         else if(a=="top")
//         {
//             if(!st.empty())
//             {
//                 cout << st.top() << '\n';
//             }
//             else cout << -1 << '\n';
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++) {
      string x;
      cin >> x;
      if(x=="push") {
        int y;
        cin >> y;
        st.push(y);
      }
      else if(x=="pop") {
        if(st.empty()) cout << -1 << '\n';
        else {
          cout << st.top() << '\n';
          st.pop();
        }
      }
      else if(x=="size") {
        cout << st.size() << '\n';
      }
      else if(x=="empty") {
        if(st.empty()) cout << 1 << '\n';
        else cout << 0 << '\n';
      }
      else if(x=="top") {
        if(st.empty()) cout << -1 << '\n';
        else cout << st.top() << '\n';
      }
    }
    return 0;
}