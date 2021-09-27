#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> q; 
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x!=0) q.push(x);
        else
        {
            if(q.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << q.top() << '\n';
                q.pop();
            }
        }
    }
    return 0;
}