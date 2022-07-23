/*
    다익스트라 익히는 가장 기초적인 문제, memset은 0,-1말고 다른값으로 초기화불가능함.
    방향그래프는 양방향그래프가 아님.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to), cost(cost) {} 
};
vector<Edge> a[20001];
bool check[20001];
int dist[20001];
int INF = 1000000000;
int main()
{
    int n,m;
    cin >> n >> m;
    int start;
    cin >> start;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
    }
    for(int i=1;i<=n;i++)
    {
        dist[i] = INF;
    }
    //memset(dist,INF,sizeof(dist));
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        int x = p.second;
        if(check[x]==true) continue;
        check[x] = true;
        for(int i=0;i<a[x].size();i++)
        {
            int y = a[x][i].to;
            if(dist[y]>dist[x]+a[x][i].cost)
            {
                dist[y] = dist[x]+a[x][i].cost;
                q.push(make_pair(-dist[y],y));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF)
        {
            cout << "INF" << '\n';
        }
        else cout << dist[i] << '\n';
    }   
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
vector<Edge> a[20001];
bool check[20001];
int dist[20001];
int main()
{
    int n,m;
    cin >> n >> m;
    int start;
    cin >> start;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
    }
    for(int i=1;i<=n;i++)
    {
        dist[i] = INF; 
    }
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
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
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to), cost(cost) {}
};
vector<Edge> a[20001];
int dist[20001];
bool check[20001];
int main()
{
    int n,m;
    cin >> n >> m;
    int start;
    cin >> start;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
    }
    for(int i=1;i<=n;i++)
    {
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<int,int>> q;
    q.push(make_pair(0,start));
    while(!q.empty())
    {
        auto p = q.top();
        q.pop();
        int x = p.second;
        if(check[x]==true) continue;
        check[x] = true;
        for(auto k:a[x])
        {
            int y = k.to;
            if(dist[y]>dist[x]+k.cost)
            {
                dist[y] = dist[x]+k.cost;
                q.push(make_pair(-dist[y],y));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define INF 1000000000
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to), cost(cost) {}
};
vector<Edge> a[20001];
int dist[20001];
bool check[20001];
int main()
{
    for(int i=1;i<=20000;i++)
    {
        dist[i] = INF;
    }
    int n,m,start;
    cin >> n >> m >> start;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
    }
    priority_queue<pair<int,int>> pq;
    dist[start] = 0;
    pq.push(make_pair(0,start));
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int x = p.second;
        if(check[x]==true) continue;
        check[x] = true;
        for(auto k:a[x])
        {
            int y = k.to;
            if(dist[y]>dist[x]+k.cost)
            {
                dist[y]=dist[x]+k.cost;
                pq.push(make_pair(-dist[y],y));
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF) cout << "INF" << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// #define INF 1000000000
// using namespace std;
// struct Edge
// {
//     int to;
//     int cost;
//     Edge(int to,int cost) : to(to),cost(cost) {}
// };
// int dist[20001];
// bool check[20001];
// vector<Edge> a[20001];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     int start;
//     cin >> start;
//     for(int i=0;i<m;i++)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         a[x].push_back(Edge(y,z));
//     }
//     for(int i=1;i<=n;i++)
//     {
//         dist[i] = INF;
//     }
//     priority_queue<pair<int,int>> pq;
//     dist[start] = 0;
//     pq.push(make_pair(0,start));
//     while(!pq.empty())
//     {
//         auto p = pq.top();
//         pq.pop();
//         int x = p.second;
//         if(check[x]==true) continue;
//         check[x] = true;
//         for(auto k:a[x])
//         {
//             int y = k.to;
//             if(dist[y]>dist[x]+k.cost)
//             {
//                 dist[y] = dist[x]+k.cost;
//                 pq.push(make_pair(-dist[y],y));
//             }
//         }
//     }
//     for(int i=1;i<=n;i++)
//     {
//         if(dist[i]==INF) cout << "INF" << '\n';
//         else cout << dist[i] << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
struct Edge {
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[20001];
bool check[20001];
int dist[20001];

int main(int argc, char const *argv[])
{
  int n,m,k;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    a[x].push_back(Edge(y,z));
  }
  for(int i=1;i<=n;i++) {
    dist[i] = INF;
  }
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,k));
  dist[k] = 0;
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

  for(int i=1;i<=n;i++) {
    if(dist[i]==INF) cout << "INF" << '\n';
    else cout << dist[i] << '\n';
  }
  return 0;
}