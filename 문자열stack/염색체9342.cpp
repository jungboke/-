/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        stack<char> st;
        string temp = "";
        bool flag = true;
        if(!(a[0]=='A'||a[0]=='B'||a[0]=='C'||a[0]=='D'||a[0]=='E'||a[0]=='F')) flag = false;
        if(a[0]=='B'||a[0]=='C'||a[0]=='D'||a[0]=='E'||a[0]=='F')
        {
            if(a[1]!='A') flag = false;
        }
        if(!(a[a.size()-1]=='A'||a[a.size()-1]=='B'||a[a.size()-1]=='C'||a[a.size()-1]=='D'||a[a.size()-1]=='E'||a[a.size()-1]=='F')) flag = false;
        if(a[a.size()-1]=='B'||a[a.size()-1]=='A'||a[a.size()-1]=='D'||a[a.size()-1]=='E'||a[a.size()-1]=='F')
        {
            if(a[a.size()-2]!='C') flag = false;
        }
        for(int i=0;i<a.size();i++)
        {
            if(st.empty()||st.top()!=a[i])
            {
                st.push(a[i]);
                temp += a[i];
            }
            else continue;
        }
        if(temp.find("AFC")==string::npos) flag = false;
        if(flag==true) cout << "Infected!" << '\n';
        else cout << "Good" << '\n';
    }
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string a;
        cin >> a;
        int end = a.size()-1;
        string temp = "";
        stack<char> st;
        if(!(a[0]=='A'||a[0]=='B'||a[0]=='C'||a[0]=='D'||a[0]=='E'||a[0]=='F'))
        {
            cout << "Good" << '\n';
            continue;
        }
        if(!(a[end]=='A'||a[end]=='B'||a[end]=='C'||a[end]=='D'||a[end]=='E'||a[end]=='F'))
        {
            cout << "Good" << '\n';
            continue;
        }
        if(a[0]=='B'||a[0]=='C'||a[0]=='D'||a[0]=='E'||a[0]=='F')
            a.erase(a.begin());
        if(a[end]=='B'||a[end]=='A'||a[end]=='D'||a[end]=='E'||a[end]=='F')
            a.erase(a.end()-1);
        for(int i=0;i<a.size();i++)
        {
            if(st.empty()||st.top()!=a[i])
            {
                st.push(a[i]);
                temp += a[i];
            }
            else continue;
        }
        if(temp=="AFC") cout << "Infected!" << '\n';
        else cout << "Good" << '\n';
    }
    return 0;
}





















