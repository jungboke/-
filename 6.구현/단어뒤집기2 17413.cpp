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
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string a = "";
    getline(cin,a);
    stack<char> st;
    string result = "";
    bool flag = false;
    for(int i=0;i<a.size();i++)
    {   
        if(a[i]==' '||a[i]=='<')
        {
            if(a[i]=='<') flag = true;
            while(!st.empty())
            {
                result+=st.top();
                st.pop();
            }
            result+=a[i];
            continue;
        }
        if(flag==true) result+=a[i];
        else st.push(a[i]);

        if(a[i]=='>') flag = false;
    }
    while(!st.empty())
    {
        result+=st.top();
        st.pop();
    }
    cout << result << '\n';
    return 0;
}













