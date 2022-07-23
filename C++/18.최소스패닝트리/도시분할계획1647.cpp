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
    Edge(int to,int cost) : to(to),cost(cost) {}
};
struct cmp
{
    bool operator() (Edge a,Edge b)
    {
        return (a.cost>b.cost);
    }
};
bool check[100001];
vector<Edge> a[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
    }
    priority_queue<Edge,vector<Edge>,cmp> pq;
    check[1] = true;
    for(auto k : a[1])
    {
        pq.push(k);
    }
    int answer = 0;
    int maxi = 0;
    while(!pq.empty())
    {
        Edge e = pq.top();
        pq.pop();
        int x = e.to;
        if(check[x]==true) continue;
        check[x] = true;
        answer += e.cost;
        if(maxi<e.cost) maxi = e.cost;
        for(auto k:a[x])
        {
            pq.push(k);
        }
    }
    cout << answer - maxi << '\n';
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
// vector<Edge> a[100001];
// bool check[100001];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         a[x].push_back(Edge(y,z));
//         a[y].push_back(Edge(x,z));
//     }
//     priority_queue<Edge,vector<Edge>,cmp> pq;
//     check[1] = true;
//     for(auto k:a[1])
//     {
//         pq.push(k);
//     }
//     vector<int> answer;
//     while(!pq.empty())
//     {
//         auto e = pq.top();
//         pq.pop();
//         int x = e.to;
//         if(check[x]==true) continue;
//         check[x] = true;
//         answer.push_back(e.cost);
//         for(auto k:a[x])
//         {
//             pq.push(k);
//         }
//     }
//     answer.erase(max_element(answer.begin(),answer.end()));
//     int cnt = 0;
//     for(int i=0;i<answer.size();i++)
//     {
//         cnt += answer[i];
//     }
//     cout << cnt << '\n';
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
int answer = 0;
int maxi = 0;

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    a[x].push_back(Edge(y,z));
    a[y].push_back(Edge(x,z));
  }
  priority_queue<Edge,vector<Edge>,cmp> pq;
  check[1] = true;
  for(auto k:a[1]) {
    pq.push(k);
  }
  while(!pq.empty()) {
    Edge e = pq.top();
    pq.pop();
    int x = e.to;
    if(check[x]==true) continue;
    check[x] = true;
    answer += e.cost;
    maxi = max(maxi,e.cost);
    for(auto k:a[x]) {
      pq.push(k);
    }
  }

  cout << answer-maxi << '\n';
  return 0;
}