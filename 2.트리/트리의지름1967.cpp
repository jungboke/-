// 더 최적의 방법이 있음, 메모리 초과발생시 vector의 크기도 살펴보기.
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
vector<pair<int,int>> a[10001];
bool check[10001];
int maxi = 0;
vector<int> leaf;
void dfs2(int num)
{
    check[num] = true;
    bool flag = false;
    for(auto k:a[num])
    {
        if(check[k.first]==false)
        {
            flag = true;
            dfs2(k.first);
        }
        if(flag==false)
        {
            leaf.push_back(num);
        }
    }
}
void dfs(int num,int sum)
{
    check[num] = true;
    bool flag = false;
    for(auto k:a[num])
    {
        if(check[k.first]==false)
        {
            flag = true;
            dfs(k.first,sum+k.second);
        }
    }
    if(flag==false)
    {
        if(maxi<sum) maxi = sum;
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x,y,m;
        cin >> x >> y >> m;
        a[x].push_back(make_pair(y,m));
        a[y].push_back(make_pair(x,m));
    }
    dfs2(1);
    for(int i=0;i<leaf.size();i++)
    {
        memset(check,false,sizeof(check));
        dfs(leaf[i],0);
    }
    cout << maxi << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
vector<Edge> a[10001];
int dist[10001];
int N;
int answer = 0;
int bfs(int x)
{
    memset(dist,-1,sizeof(dist));
    queue<int> q;
    q.push(x);
    dist[x] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto k:a[x])
        {
            int y = k.to;
            if(dist[y]==-1)
            {
                q.push(y);
                dist[y] = dist[x] + k.cost;
            }
        }
    }
    int maxi = 0;
    int m_idx = 0;
    for(int i=1;i<=N;i++)
    {
        if(dist[i]>maxi)
        {
            maxi = dist[i];
            m_idx = i;
        }
    }
    answer += maxi;
    return m_idx;
}

int main()
{
    int n;
    cin >> n;
    N=n;
    int next = 0;
    for(int i=0;i<n-1;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    next = bfs(1);
    answer = 0;
    bfs(next);
    cout << answer << '\n';
    return 0;
}