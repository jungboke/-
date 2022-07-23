/*
    문자열에서 연속되는 문자를 하나의 문자로 바꾸는 방법은 stack보다 for문을 돌리는게 더 빠를듯함.
    두개의 문자로만 이루어져 있는 문제에서 위방법을 사용하면 각 문자의 개수는 n,n 또는 n,n+1이 될 수밖에 없음. 
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a = "";
    cin >> a;
    stack<char> st;
    for(int i=0;i<a.size();i++)
    {
        if(st.empty()||st.top()!=a[i]) st.push(a[i]);
        else continue;
    }
    a = "";
    while(!st.empty())
    {
        a += st.top();
        st.pop();
    }
    reverse(a.begin(),a.end());
    int bcount = 0;
    int rcount = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='B') bcount++;
        else if(a[i]=='R') rcount++;
    }
    if(bcount>=rcount) cout << 1+rcount << '\n';
    else cout << 1+bcount << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    string result = "";
    char temp = ' ';
    for(int i=0;i<n;i++)
    {
        if(temp!=a[i])
        {
            result+=a[i];
            temp = a[i];
        }
    }
    int bcount = 0;
    int rcount = 0;
    int answer = 0;
    for(int i=0;i<result.size();i++)
    {
        if(result[i]=='B') bcount++;
        else rcount++;
    }
    answer = min(bcount,rcount) + 1;
    cout << answer << '\n'; 
    return 0;
}