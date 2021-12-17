/*
    후위표기식 알고리즘은 직접 구현하는 거보다 외우는게 좋을듯함.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a;
    cin >> a;
    string answer = "";
    stack<char> st;
    for(int i=0;i<a.size();i++)
    {
        if(!(a[i]=='('||a[i]==')'))
        {
            if(isalpha(a[i])!=0) answer += a[i];
            else
            {
                if(a[i]=='*'||a[i]=='/')
                {
                    while(!st.empty()&&(st.top()=='*'||st.top()=='/'))
                    {
                        answer += st.top();
                        st.pop();
                    }
                    st.push(a[i]);
                }
                else if(a[i]=='+'||a[i]=='-')
                {
                    while(!st.empty()&&st.top()!='(')
                    {
                        answer += st.top();
                        st.pop();
                    }
                    st.push(a[i]);
                }
            }
        }
        else if(a[i]==')')
        {
            while(!st.empty()&&st.top()!='(')
            {
                answer += st.top();
                st.pop();
            }
            st.pop();
        }
        else st.push(a[i]);
    }
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    cout << answer << '\n';
    return 0;
}