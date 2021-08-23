#include <vector>
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
}