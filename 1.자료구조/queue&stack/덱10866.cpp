#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        if(a=="push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if(a=="push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if(a=="pop_front")
        {
            if(!dq.empty())
            {
                int x = dq.front();
                dq.pop_front();
                cout << x << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(a=="pop_back")
        {
            if(!dq.empty())
            {
                int x = dq.back();
                dq.pop_back();
                cout << x << '\n';
            }
            else cout << -1 << '\n';
        }
        else if(a=="size")
        {
            cout << dq.size() << '\n';
        }
        else if(a=="empty")
        {
            cout << dq.empty() << '\n';
        }
        else if(a=="front")
        {
            if(!dq.empty()) cout << dq.front() << '\n';
            else cout << -1 << '\n';
        }
        else if(a=="back")
        {
            if(!dq.empty()) cout << dq.back() << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}
// deque는 double ended queue로 queue기능에 back관련기능 추가되었고, vector처럼 배열판정이다.