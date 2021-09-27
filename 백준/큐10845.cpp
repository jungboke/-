#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    deque<int> q;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        if(x=="push")
        {
            int num;
            cin >> num;
            q.push_back(num);
        }
        else if(x=="pop")
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                int num = q.front();
                q.pop_front();
                cout << num << '\n';
            }
        }
        else if(x=="size")
        {
            cout << q.size() << '\n';
        }
        else if(x=="empty")
        {
            cout << q.empty() << '\n';
        }
        else if(x=="front")
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.front() << '\n';
            }
        }
        else if(x=="back")
        {
            if(q.empty()) cout << -1 << '\n';
            else
            {
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}