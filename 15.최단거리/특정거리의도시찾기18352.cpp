// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// struct Edge 
// {
//     int to;
//     int cost;
//     Edge(int to,int cost) : to(to),cost(cost) {}
// };
// vector<Edge> a[300001];
// int dist[300001];
// bool check[300001];
// int INF = 1000000000;
// int main()
// {
//     int n,m,k,start;
//     cin >> n >> m >> k >> start;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(Edge(y,1));
//     }
//     for(int i=1;i<=n;i++)
//     {
//         dist[i] = INF;
//     }
//     dist[start] = 0;
//     priority_queue<pair<int,int>> q;
//     q.push(make_pair(0,start));
//     while(!q.empty())
//     {
//         auto p = q.top();
//         q.pop();
//         int x = p.second;
//         if(check[x]==true) continue;
//         check[x] = true;
//         for(int i=0;i<a[x].size();i++)
//         {
//             int y = a[x][i].to;
//             if(dist[y]>dist[x]+a[x][i].cost)
//             {
//                 dist[y] = dist[x] + a[x][i].cost;
//                 q.push(make_pair(-dist[y],y));
//             }
//         }
//     }
//     bool flag = false;
//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]==k)
//         {
//             flag = true;
//             cout << i << '\n';
//         }
//     }
//     if(flag==false) cout << -1 << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
struct Edge{
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[300001];
int dist[300001];
bool check[300001];
int INF = 1000000000;

int main(int argc, char const *argv[])
{
  int n,m,k,start;
  cin >> n >> m >> k >> start;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(Edge(y,1));
  }
  for(int i=1;i<=n;i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,start));
  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int x = p.second;
    if(check[x]==true) continue;
    check[x] = true;
    for(auto k:a[x]) {
      int y = k.to;
      if(dist[y]>dist[x]+k.cost) {
        dist[y] = dist[x]+k.cost;
        pq.push(make_pair(-dist[y],y));
      }
    }
  }
  bool flag = false;

  for(int i=1;i<=n;i++) {
    if(dist[i]==k) {
      flag = true;
      cout << i << '\n';
    }
  }
  if(flag==false) cout << -1 << '\n';
  return 0;
}
