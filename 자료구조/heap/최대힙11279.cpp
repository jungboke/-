#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> pq;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==0)
        {
            if(pq.empty()) cout << 0 << '\n';
            else
            {
                int temp = pq.top();
                pq.pop();
                cout << temp << '\n';
            }
        }
        else pq.push(x);
    }
    return 0;
}