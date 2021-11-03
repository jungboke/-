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