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