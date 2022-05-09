/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 999999999;
using namespace std;
int dist[100001];
int main()
{
    for(int i=0;i<100001;i++)
    {
        dist[i] = MAX;
    }
    int n,k;
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x-1>=0&&x-1<=100000&&dist[x-1]>dist[x]+1)
        {
            q.push(x-1);
            dist[x-1] = dist[x] + 1;
        }
        if(x+1>=0&&x+1<=100000&&dist[x+1]>dist[x]+1)
        {
            q.push(x+1);
            dist[x+1] = dist[x] + 1;
        }
        if(2*x>=0&&2*x<=100000&&dist[2*x]>dist[x])
        {
            q.push(2*x);
            dist[2*x] = dist[x];
        }
    }
    cout << dist[k] << '\n';
    return 0;
}
*/
/*
    1차원 배열내 최소이동거리 구하기위한 bfs는 이 방식이 유용할듯함.
    deque나 priority_queue를 사용하여 가중치가 다른 경우 문제를 해결할 수도 있음.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #define INF 1000000000
// using namespace std;
// int dist[100001];
// bool check[100001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<=100000;i++)
//     {
//         dist[i] = INF;
//     }
//     dist[n] = 0;
//     priority_queue<pair<int,int>> q;
//     q.push(make_pair(0,n));
//     while(!q.empty())
//     {
//         auto p = q.top();
//         q.pop();
//         int x = p.second;
//         if(check[x]==true) continue;
//         check[x] = true;
//         if(x+1<=100000&&dist[x+1] > dist[x]+1)
//         {
//             dist[x+1] = dist[x] + 1;
//             q.push(make_pair(-dist[x+1],x+1));
//         }
//         if(x-1>=0&&dist[x-1] > dist[x]+1)
//         {
//             dist[x-1] = dist[x] + 1;
//             q.push(make_pair(-dist[x-1],x-1));
//         }
//         if(2*x<=100000&&dist[2*x] > dist[x])
//         {
//             dist[2*x] = dist[x];
//             q.push(make_pair(-dist[2*x],2*x));
//         }
//     }
//     cout << dist[m] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dist[100001];
bool check[100001];

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin >> n >> k;
  for(int i=0;i<=100000;i++) {
    dist[i] = INF;
  }
  priority_queue<pair<int,int>> pq;
  pq.push(make_pair(0,n));
  dist[n] = 0;
  while(!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int x = p.second;
    if(check[x]==true) continue;
    check[x] = true;
    if(x+1<=100000&&dist[x+1]>dist[x]+1) {
      dist[x+1] = dist[x]+1;
      pq.push(make_pair(-dist[x+1],x+1));
    }
    if(x-1>=0&&dist[x-1]>dist[x]+1) {
      dist[x-1] = dist[x]+1;
      pq.push(make_pair(-dist[x-1],x-1));
    }
    if(2*x<=100000&&dist[2*x]>dist[x]) {
      dist[2*x] = dist[x];
      pq.push(make_pair(-dist[2*x],2*x));
    }
  }

  cout << dist[k] << '\n';
  return 0;
}
