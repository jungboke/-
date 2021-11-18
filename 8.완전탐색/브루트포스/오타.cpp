#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
bool check(string temp)
{
    bool flag = true;
    stack<char> st;
    for(int i=0;i<temp.size();i++)
    {
        if(st.empty()||st.top()==temp[i]) st.push(temp[i]);
        else st.pop();

        if(!st.empty()&&st.top()==')')
        {
            flag = false;
            break;
        }
    }
    if(st.size()!=0) flag = false;
    return flag;
}
int main()
{
    string temp = "";
    cin >> temp;
    int cnt = 0;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='(')
        {
            temp[i] = ')';
            if(check(temp)==true) cnt++;
            temp[i] = '(';
        }
        else if(temp[i]==')')
        {
            temp[i] = '(';
            if(check(temp)==true) cnt++;
            temp[i] = ')';
        }
    }
    cout << cnt << '\n';
    return 0;
}
/// 시간초과