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
    int sum = 0;
    int temp = 1;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()||a[i]=='('||a[i]=='[')
        {
            if(a[i]=='(')
            {
                temp *= 2;
            }
            else if(a[i]=='[')
            {
                temp *= 3;
            }
            st.push(a[i]);
        }
        else
        {
            if(st.top()=='('&&a[i]==')')
            {
                if(a[i-1]=='(')
                {
                    sum += temp;
                }
                temp /= 2;
                st.pop();
            }   
            else if(st.top()=='['&&a[i]==']')
            {
                if(a[i-1]=='[')
                {
                    sum += temp;
                }
                temp /= 3;
                st.pop();
            }   
            else
            {
                sum = 0;
                break;
            }      
        }
        
        if(!st.empty()&&(st.top()==')'||st.top()==']'))
        {
            sum = 0;
            break;
        }
    }
    if(!st.empty()) sum = 0;
    cout << sum << '\n';
    return 0;
}
/*
    쇠막대기 자르기와 비슷한 유형의 문제. 분배법칙을 생각해내야함.
*/