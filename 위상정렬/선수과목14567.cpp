/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[1001];
int ind[1001];
int dist[1001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        ind[y] += 1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            dist[i] = 1;
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<a[x].size();i++)
        {
            int y = a[x][i];
            ind[y]-=1;
            if(ind[y]==0)
            {
                q.push(y);
                dist[y] = dist[x] + 1;
            }    
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[1001];
int ind[1001];
int dist[1001];
int main()
{  
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        ind[y]+=1;
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            dist[i] = 1;
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto k:a[x])
        {
            ind[k]--;
            if(ind[k]==0)
            {
                q.push(k);
                dist[k] = dist[x] + 1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}















