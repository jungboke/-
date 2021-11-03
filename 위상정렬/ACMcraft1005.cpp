#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
vector<int> a[1001];
int ind[1001];
int dist[1001];
int total[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++)
        {
            cin >> dist[i];
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            ind[y]++;
        }
        int target;
        cin >> target;
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
                total[i] = dist[i];
            }
        }
        while(!q.empty())
        {
            int x = q.front();
            q.pop();
            for(auto k:a[x])
            {
                ind[k]--;
                if(total[k]<total[x]+dist[k]) total[k] = total[x]+dist[k];
                if(ind[k]==0)
                {
                    q.push(k);
                }
            }
        }
        cout << total[target] << '\n';
        for(int i=1;i<=n;i++) a[i].clear();
        memset(ind,0,sizeof(ind));
        memset(dist,0,sizeof(dist));
        memset(total,0,sizeof(total));
    }
    return 0;
}