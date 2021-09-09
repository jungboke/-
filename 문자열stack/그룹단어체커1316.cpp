/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int answer = 0;
    while(n--)
    {
        string a;
        cin >> a;
        stack<char> st;
        map<char,int> m;
        bool flag = true;
        for(int i=0;i<a.size();i++)
        {
            if(st.empty()||st.top()!=a[i])
            {
                if(m[a[i]]==0) m[a[i]]++;
                else
                {
                    flag = false;
                    break;
                }
                st.push(a[i]);
            }
            else continue;
        }
        if(flag==true) answer++;
    }
    cout << answer << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        stack<char> st;
        set<char> s;
        string a;
        cin >> a;
        for(int i=0;i<a.size();i++)
        {
            if(st.empty()||st.top()!=a[i])
            {
                st.push(a[i]);
                s.insert(a[i]);
            }
            else continue;
        }
        if(s.size()==st.size()) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}






















