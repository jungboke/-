/*
    구현문제처럼 문제이해가 중요함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin >> a;
    stack<char> st;
    int answer = 0;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()||st.top()==a[i]) st.push(a[i]);
        else
        {
            if(a[i-1]!=a[i])
            {
                st.pop();
                answer += st.size();
            }
            else
            {
                st.pop();
                answer += 1;
            }
        }

        if(!st.empty()&&st.top()==')') break;
    }
    cout << answer << '\n';
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a;
    cin >> a;
    stack<char> st;
    int answer = 0;
    int cnt = 0;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()||st.top()==a[i])
        {
            st.push(a[i]);
            cnt++;
        }
        else
        {
            st.pop();
            if(a[i-1]==')')
            {
                answer+=1;
            }
            else
            {
                answer+=st.size();
            }
        }

        if(!st.empty()&&st.top()==')') break;
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     stack<char> st;
//     string result;
//     cin >> result;
//     int answer = 0;
//     for(int i=0;i<result.size();i++)
//     {
//         if(st.empty()||st.top()==result[i]) st.push(result[i]);
//         else
//         {
//             if(result[i-1]=='(')
//             {
//                 st.pop();
//                 answer += st.size();
//             }
//             else
//             {
//                 st.pop();
//                 answer += 1;
//             }
//         }
//         if(!st.empty()&&st.top()==')') break;
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  string a;
  cin >> a;
  stack<char> st;
  int answer = 0;
  for(int i=0;i<a.size();i++) {
    if(st.empty()||a[i]=='(') st.push(a[i]);
    else {
      st.pop();
      if(a[i-1]==a[i]) {
        answer += 1;
      }
      else answer += st.size();
    }
  }
  cout << answer << '\n';
  return 0;
}