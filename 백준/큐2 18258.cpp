#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    int t;
    cin >> t;
    int end = -1;
    while(t--)
    {
        string a;
        cin >> a;
        if(a=="push")
        {
            int x;
            cin >> x;
            q.push(x);
            end = x;
        }
        else if(a=="pop")
        {
            if(!q.empty())
            {
                int x = q.front();
                q.pop();
                cout << x << '\n';
            }
            else cout << -1 << '\n';
            if(q.empty()) end = -1;
        }
        else if(a=="size")
        {
            cout << q.size() << '\n';
        }
        else if(a=="empty")
        {
            cout << q.empty() << '\n';
        }
        else if(a=="front")
        {
            if(!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(a=="back")
        {
            cout << end << '\n';
        }
    }
    return 0;
}