#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

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
        bool flag = true;
        for(int i=0;i<a.size();i++)
        {
            if(st.empty()||st.top()==a[i]) st.push(a[i]);
            else st.pop();

            if(!st.empty()&&st.top()==')')
            {
                flag = false;
                break;
            }
        }
        if(st.size()!=0) flag = false;
        if(flag==true) cout << "YES" << '\n';
        else cout << "NO" << '\n'; 
    }
    return 0;
}