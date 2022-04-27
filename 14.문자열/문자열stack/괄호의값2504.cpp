/*
    쇠막대기 자르기와 비슷한 유형의 문제. 분배법칙을 생각해내야함.
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
    int sum = 0;
    int temp = 1;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()||a[i]=='('||a[i]=='[')
        {
            if(a[i]=='(')
            {
                temp *= 2;
            }
            else if(a[i]=='[')
            {
                temp *= 3;
            }
            st.push(a[i]);
        }
        else
        {
            if(st.top()=='('&&a[i]==')')
            {
                if(a[i-1]=='(')
                {
                    sum += temp;
                }
                temp /= 2;
                st.pop();
            }   
            else if(st.top()=='['&&a[i]==']')
            {
                if(a[i-1]=='[')
                {
                    sum += temp;
                }
                temp /= 3;
                st.pop();
            }   
            else
            {
                sum = 0;
                break;
            }      
        }
        
        if(!st.empty()&&(st.top()==')'||st.top()==']'))
        {
            sum = 0;
            break;
        }
    }
    if(!st.empty()) sum = 0;
    cout << sum << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string result;
//     cin >> result;
//     stack<char> st;
//     bool flag = true;
//     int sum = 0;
//     int temp = 1;
//     for(int i=0;i<result.size();i++)
//     {
//         if(st.empty()||result[i]=='('||result[i]=='[')
//         {
//             if(result[i]=='(') temp *= 2;
//             else if(result[i]=='[') temp *= 3;
//             st.push(result[i]);
//         }
//         else
//         {
//             if(result[i]==')')
//             {
//                 if(result[i-1]=='(') sum += temp;
//                 temp /= 2;
//                 if(st.top()=='(') st.pop();
//             }
//             else if(result[i]==']')
//             {
//                 if(result[i-1]=='[') sum += temp;
//                 temp /= 3;
//                 if(st.top()=='[') st.pop();
//             }
//         }

//         if(!st.empty()&&(st.top()==')'||st.top()==']'))
//         {
//             flag = false;
//             break;
//         }
//     }
//     if(st.size()!=0) flag = false;
//     if(flag==false) cout << 0 << '\n';
//     else cout << sum << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  string a;
  cin >> a;
  stack<char> st;
  int answer = 0;
  int cnt = 1;
  bool flag = true;
  for(int i=0;i<a.size();i++) {
    if(st.empty()||a[i]=='('||a[i]=='[') {
      if(a[i]=='(') cnt *= 2;
      else if(a[i]=='[') cnt *= 3;

      st.push(a[i]);  
    }
    else {
      if((st.top()=='('&&a[i]!=')')||(st.top()=='['&&a[i]!=']')) {
        flag = false;
        break;
      }
      if(a[i-1]=='('||a[i-1]=='[') answer += cnt;
      if(a[i]==')') cnt /= 2;
      else if(a[i]==']') cnt /= 3;

      st.pop();
    }

    if(!st.empty()&&(st.top()==')'||st.top()==']')) {
      flag = false;
      break;
    }
  }
  if(!st.empty()) flag = false;

  if(flag==false) cout << 0 << '\n';
  else cout << answer << '\n';
  return 0;
}
