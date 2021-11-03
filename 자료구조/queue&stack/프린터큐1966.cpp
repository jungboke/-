#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            q.push(make_pair(a[i],i));
        }
        int cnt = 1;
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(*max_element(a.begin(),a.end())<=p.first)
            {
                if(p.second==m)
                {
                    cout << cnt << '\n';
                    break;
                }
                cnt++;
                a.erase(max_element(a.begin(),a.end()));
            }
            else q.push(p);
        }
    }
    return 0;
}