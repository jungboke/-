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
bool check[1001];
vector<Edge> a[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int z;
            cin >> z;
            if(i==j) continue;
            a[i].push_back(Edge(j,z));
            a[j].push_back(Edge(i,z));
        }
    }
    priority_queue<Edge,vector<Edge>,cmp> pq;
    check[1] = true;
    for(auto k:a[1])
    {
        pq.push(k);
    }
    long long sum = 0;
    while(!pq.empty())
    {
        auto e = pq.top();
        pq.pop();
        int x = e.to;
        if(check[x]==true) continue;
        check[x] = true;
        sum += e.cost;
        for(auto k:a[x])
        {
            pq.push(k);
        }
    }
    cout << sum << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// struct Edge
// {
//     int to;
//     int cost;
//     Edge(int to,int cost) : to(to),cost(cost) {}
// };
// struct cmp
// {
//     bool operator()(Edge a,Edge b)
//     {
//         return (a.cost>b.cost);
//     }
// };
// vector<Edge> a[1001];
// bool check[1001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             int x;
//             cin >> x;
//             if(i==j) continue;
//             a[i].push_back(Edge(j,x));
//         }
//     }
//     priority_queue<Edge,vector<Edge>,cmp> pq;
//     check[1] = true;
//     for(auto k:a[1])
//     {
//         pq.push(k);
//     }
//     long long answer = 0;
//     while(!pq.empty())
//     {
//         auto e = pq.top();
//         pq.pop();
//         int x = e.to;
//         if(check[x]==true) continue;
//         check[x] = true;
//         answer += e.cost;
//         for(auto k:a[x])
//         {
//             pq.push(k);
//         }
//     }
//     cout << answer << '\n';
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
vector<Edge> a[1001];
bool check[1001];

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      int x;
      cin >> x;
      if(i>=j) continue;
      a[i].push_back(Edge(j,x));
      a[j].push_back(Edge(i,x));
    }
  }
  priority_queue<Edge,vector<Edge>,cmp> pq;
  check[1] = true;
  for(auto k:a[1]) {
    pq.push(k);
  }
  long long answer = 0;
  while(!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    int x = e.to;
    if(check[x]==true) continue;
    check[x] = true;
    answer += e.cost;
    for(auto k:a[x]) {
      pq.push(k);
    }
  }

  cout << answer << '\n';
  return 0;
}
