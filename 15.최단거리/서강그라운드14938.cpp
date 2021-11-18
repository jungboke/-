// 다익스트라로 정점마다 최단거리값 구해서 배열에 넣기
// 아이템 수 배열 생성
// for문으로 배열돌면서 수색범위내 값 전부 더하기
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#define INF 1000000000
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
int item[150];
int dist[150];
bool check[150];
vector<Edge> a[150];
int N,M; 
int dst(int start)
{
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    dist[start] = 0;
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        int x = p.second;
        if(check[x]==true) continue;
        check[x] = true;
        for(auto k : a[x])
        {
            int y = k.to;
            if(dist[y]>dist[x]+k.cost)
            {
                dist[y] = dist[x]+k.cost;
                q.push(make_pair(-dist[y],y));
            }
        }
    }
    int sum = 0;
    for(int i=1;i<=N;i++)
    {
        if(dist[i]<=M) sum += item[i];
    } 
    return sum;
}
int main()
{
    int n,m,r;
    cin >> n >> m >> r;
    N=n;M=m;
    int maxi = 0;
    for(int i=1;i<=n;i++) cin >> item[i];
    for(int i=0;i<r;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dist[j] = INF;
        }
        memset(check,false,sizeof(check));
        if(maxi<dst(i)) maxi = dst(i);
    }
    cout << maxi << '\n';
    return 0;
}