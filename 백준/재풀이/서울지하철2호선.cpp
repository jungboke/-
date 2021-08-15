#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
vector<int> a[3001];
int check[3001];
int dist[3001];
int dfs(int x,int ix)
{
    if(check[x]==1)
    {
        return x;
    }
    check[x] = 1;
    for(int k : a[x])
    {
        if(k==ix) continue;
        int m = dfs(k,x);
        if(m>0)
        {
            check[x] = 2;
            if(x==m) return -2;
            else return m;
        }
        else if(m==-2) return -2;
    }
    return -1; //
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,1);
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==2)
        {
            dist[i] = 0;
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int k : a[x])
        {
            if(dist[k]==-1)
            {
                q.push(k);
                dist[k] = dist[x]+1;
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