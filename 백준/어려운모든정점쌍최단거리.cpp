#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define rank _rank
using namespace std;
int parent[100001];
int rank[100001];
bool check[100001];
vector<int> a[100001];
int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = Find(parent[x]);
}
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) swap(x,y);
    parent[y] = x;
    if(rank[x]==rank[y]) rank[x] += 1;
}
bool bfs(int x,int y)
{
    queue<int> q;
    q.push(x);
    check[x] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x==y) return true;
        for(auto k:a[x])
        {
            if(check[k]==false)
            {
                q.push(k);
                check[k] = true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++)
    {
        parent[i] = i;
    }
    int sx;
    int ex;
    for(int i=0;i<m;i++)
    {
        if(i==k-1)
        {
            int x,y;
            cin >> x >> y;
            sx = x;
            ex = y;
            continue;
        }
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
        Union(x,y); 
    }
    if(bfs(sx,ex)==true) cout << 0 << '\n';
    else
    {
        long long one = 0;
        long long two = 0;
        for(int i=1;i<=n;i++)
        {
            if(Find(1)==Find(i)) one++;
            else two++;
        }
        cout << one*two << '\n';
    }
    return 0;
}