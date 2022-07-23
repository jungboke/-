/*
    cout.setf(ios::fixed);
    cout.precision(?);
    를 통해 출력되는 소수점 범위제한 가능.
    간단한 알파벳은 map사용대신 a[i]-'A'처럼 배열을 사용.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int alp[100];
int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    stack<double> st;
    for(int i=0;i<a.size();i++)
    {
        if(isalpha(a[i])!=0)
        {
            if(alp[a[i] - 'A']==0)
            {
                cin >> alp[a[i] - 'A'];
            }
            st.push(alp[a[i] - 'A']);
        }
        else
        {
            double y = st.top();
            st.pop();
            double x = st.top();
            st.pop();
            if(a[i]=='+')
            {
                double z = x+y;
                st.push(z);
            }
            else if(a[i]=='-')
            {
                double z = x-y;
                st.push(z);
            }
            else if(a[i]=='*')
            {
                double z = x*y;
                st.push(z);
            }
            else if(a[i]=='/')
            {
                double z = x/y;
                st.push(z);
            }
        }
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << st.top() << '\n';
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int alp[30];
int main()
{
    cout.setf(ios::fixed);
    cout.precision(2);
    int n;
    cin >> n;
    string result = "";
    cin >> result;
    stack<double> st;
    for(int i=0;i<n;i++)
    {
        cin >> alp[i];
    }
    for(int i=0;i<result.size();i++)
    {
        if(isalpha(result[i])!=0)
        {
            st.push(alp[result[i]-'A']);
        }
        else
        {
            double b = st.top();
            st.pop();
            double a = st.top();
            st.pop();
            if(result[i]=='+')
            {
                st.push(a+b);
            }
            else if(result[i]=='-')
            {
                st.push(a-b);
            }
            else if(result[i]=='*')
            {
                st.push(a*b);
            }
            else if(result[i]=='/')
            {
                st.push(a/b);
            }
        }
    }
    cout << st.top() << '\n';
    return 0;
}
