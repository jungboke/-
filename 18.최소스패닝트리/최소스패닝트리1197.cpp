/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to), cost(cost) {}
};
struct cmp
{
    bool operator()(Edge a,Edge b)
    {
        return (a.cost>b.cost);
    }
};
vector<Edge> a[10001];
bool c[10001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    c[1] = true;
    priority_queue<Edge,vector<Edge>,cmp> q;
    for(int i=0;i<a[1].size();i++)
    {
        q.push(a[1][i]);
    }
    int ans = 0;
    while(!q.empty())
    {
        Edge e = q.top();
        q.pop();
        int x = e.to;
        if(c[x]==true) continue;
        c[x] = true;
        ans += e.cost;
        for(int i=0;i<a[x].size();i++)
        {
            q.push(a[x][i]);
        }
    }
    cout << ans << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
struct cmp
{
    bool operator()(Edge a,Edge b)
    {
        return (a.cost>b.cost);
    }
};
vector<Edge> a[10001];
bool check[10001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    check[1] = true;
    priority_queue<Edge,vector<Edge>,cmp> q;
    for(auto k:a[1])
    {
        q.push(k);
    }
    int answer = 0;
    while(!q.empty())
    {
        Edge e = q.top();
        q.pop();
        int x = e.to;
        if(check[x]==true) continue;
        check[x] = true;
        answer += e.cost;
        for(auto k:a[x])
        {
            q.push(k);
        }
    }
    cout << answer << '\n';
    return 0;
}














