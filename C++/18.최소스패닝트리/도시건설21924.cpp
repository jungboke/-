/*
    최소스패닝트리.
    최소스패닝값 구한후 전체거리합에서 빼준 값 계산.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// struct Edge
// {
//     int to;
//     long long cost;
//     Edge(int to,long long cost) : to(to),cost(cost) {}
// };
// struct cmp
// {
//     bool operator()(Edge a,Edge b)
//     {
//         return (a.cost>b.cost);
//     }
// };
// bool check[100001];
// vector<Edge> a[100001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     long long total = 0;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         long long z;
//         cin >> x >> y >> z;
//         a[x].push_back(Edge(y,z));
//         a[y].push_back(Edge(x,z));
//         total += z;
//     }
//     priority_queue<Edge,vector<Edge>,cmp> pq;
//     check[1] = true;
//     for(auto k:a[1])
//     {
//         pq.push(k);
//     }
//     long long sum = 0;
//     while(!pq.empty())
//     {
//         auto e = pq.top();
//         pq.pop();
//         int x = e.to;
//         if(check[x]==true) continue;
//         check[x] = true;
//         sum += e.cost;
//         for(auto k:a[x])
//         {
//             pq.push(k);
//         }
//     }
//     bool flag = true;
//     for(int i=1;i<=n;i++)
//     {
//         if(check[i]==false) flag = false;
//     }
//     if(flag==false) cout << -1 << '\n';
//     else cout << total-sum << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
struct cmp {
  bool operator()(Edge a, Edge b) {
    return (a.cost>b.cost);
  }
};
vector<Edge> a[100001];
bool check[100001];

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  long long total_sum = 0;
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    a[x].push_back(Edge(y,z));
    a[y].push_back(Edge(x,z));
    total_sum += z;
  }
  priority_queue<Edge,vector<Edge>,cmp> pq;
  check[1] = true;
  for(auto k:a[1]) {
    pq.push(k);
  }
  long long sum = 0;
  while(!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    int x = e.to;
    if(check[x]==true) continue;
    check[x] = true;
    sum += e.cost;
    for(auto k:a[x]) {
      pq.push(k);
    }
  }
  bool flag = true;
  for(int i=1;i<=n;i++) {
    if(check[i]==false) flag = false;
  }
  if(flag==false) cout << -1 << '\n';
  else cout << total_sum - sum << '\n';
  return 0;
}