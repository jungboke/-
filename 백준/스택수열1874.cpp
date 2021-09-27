#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    stack<int> st;
    vector<char> op;
    int k = 1;
    bool flag = true;
    while(n--)
    {
        int x;
        cin >> x;
        while(st.empty()||st.top()<x)
        {
            st.push(k);
            k++;
            op.push_back('+');
        }
        if(st.top()!=x)
        {
            flag = false;
            break;
        }
        else
        {
            st.pop();
            op.push_back('-');
        }
    }
    if(flag==true)
    {
        for(int i=0;i<op.size();i++)
        {
            cout << op[i] << '\n';
        }
    }
    else cout << "NO" << '\n';
    return 0;
}