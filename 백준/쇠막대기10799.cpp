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
/*
    구현문제처럼 문제이해가 중요함.
*/