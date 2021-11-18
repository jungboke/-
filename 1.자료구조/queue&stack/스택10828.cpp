#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> st;
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        if(a=="push")
        {
            int b;
            cin >> b;
            st.push(b);
        }
        else if(a=="pop")
        {
            if(!st.empty())
            {
                int x = st.top();
                st.pop();
                cout << x << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(a=="size")
        {
            cout << st.size() << '\n';
        }
        else if(a=="empty")
        {
            cout << st.empty() << '\n';
        }
        else if(a=="top")
        {
            if(!st.empty())
            {
                cout << st.top() << '\n';
            }
            else cout << -1 << '\n';
        }
    }
    return 0;
}