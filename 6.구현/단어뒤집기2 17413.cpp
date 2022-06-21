/*#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string result = "";
    string a = "";
    getline(cin,a);
    string temp = "";
    stack<char> st;
    bool flag = false;
    for(int i=0;i<a.size();i++)
    {
        if(flag==false)
        {
            if(!(a[i] == ' ' || a[i] == '<'))
            {
                st.push(a[i]);
            }
            else if(a[i] == ' ' || a[i] == '<')
            {
                while(!st.empty())
                {
                    result += st.top();
                    st.pop();
                }
                result += a[i];
                if(a[i]=='<') flag = true;
            }
        }
        else
        {
            result += a[i];
            if(a[i]=='>') flag = false;
        }
    }
    while(!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << result << '\n';
    return 0;
}*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <stack>
// using namespace std;

// int main()
// {
//     string a = "";
//     getline(cin,a);
//     stack<char> st;
//     string result = "";
//     bool flag = false;
//     for(int i=0;i<a.size();i++)
//     {   
//         if(a[i]==' '||a[i]=='<')
//         {
//             if(a[i]=='<') flag = true;
//             while(!st.empty())
//             {
//                 result+=st.top();
//                 st.pop();
//             }
//             result+=a[i];
//             continue;
//         }
//         if(flag==true) result+=a[i];
//         else st.push(a[i]);

//         if(a[i]=='>') flag = false;
//     }
//     while(!st.empty())
//     {
//         result+=st.top();
//         st.pop();
//     }
//     cout << result << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  string x;
  getline(cin,x);
  string answer = "";
  string temp = "";
  bool flag = false;
  for(int i=0;i<x.size();i++) {
    if(x[i]=='<') {
      reverse(temp.begin(),temp.end());
      answer += temp;
      temp = "";
      flag = true;
    }
    else if(x[i]=='>') {
      answer += x[i];
      flag = false;
      continue;
    }
    if(flag==true) answer += x[i];
    else {
      if(x[i]==' ') {
        reverse(temp.begin(),temp.end());
        answer += temp;
        answer += ' ';
        temp = "";
      } else temp += x[i];
    }
  }
  if(temp!="") {
    reverse(temp.begin(),temp.end());
    answer += temp;
  }
  cout << answer << '\n';
  return 0;
}