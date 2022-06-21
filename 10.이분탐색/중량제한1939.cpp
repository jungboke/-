/*
    bfs와 이분탐색이 결합된 문제.
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
    long long cost;
    Edge(int to,long long cost) : to(to), cost(cost) {}
};
vector<Edge> a[100001];
bool check[100001];
bool bfs(int x,int target,long long bound)
{
    memset(check,false,sizeof(check));
    queue<int> q;
    check[x] = true;
    q.push(x);
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x==target) return true;
        for(auto k:a[x])
        {
            if(check[k.to]==false&&k.cost>=bound)
            {
                q.push(k.to);
                check[k.to] = true;
            }
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    long long start = 0;
    long long end = 0;
    for(int i=0;i<m;i++)
    {
        int x,y;
        long long z;
        cin >> x >> y >> z;
        a[x].push_back(Edge(y,z));
        a[y].push_back(Edge(x,z));
        if(end<z) end = z;
    }
    int sx,ex;
    cin >> sx >> ex;
    long long maxi = 0;
    while(start<=end)
    {
        long long mid = (start+end) / 2;
        bool flag = bfs(sx,ex,mid);
        if(flag==true)
        {
            if(maxi<mid) maxi = mid;
            start = mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    cout << maxi << '\n';
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
// vector<Edge> a[100001];
// bool check[100001];
// bool bfs(int sx,int ex,int mid)
// {
//     memset(check,false,sizeof(check));
//     queue<int> q;
//     check[sx] = true;
//     q.push(sx);
//     while(!q.empty())
//     {
//         int x= q.front();
//         q.pop();
//         for(auto k:a[x])
//         {
//             if(check[k.to]==true||k.cost<mid) continue;
//             q.push(k.to);
//             check[k.to] = true;
//             if(k.to==ex) return true;
//         }
//     }
//     return false;
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     int maxi1 = 0;
//     for(int i=0;i<m;i++)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         a[x].push_back(Edge(y,z));
//         a[y].push_back(Edge(x,z));
//         maxi1 = max(maxi1,z);
//     }
//     int sx,ex;
//     cin >> sx >> ex;
//     int start = 0;
//     int end = maxi1;
//     int maxi = 0;
//     while(start<=end)
//     {
//         int mid = (start+end)/2;
//         if(bfs(sx,ex,mid)==true)
//         {
//             start = mid+1;
//             maxi = max(maxi,mid);
//         }
//         else end = mid-1;
//     }
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  int cost;
  Edge(int to, int cost) : to(to), cost(cost) {}
};
vector<Edge> a[10001];
bool check[10001];

bool bfs(int sx, int ex, int m) {
  memset(check,false,sizeof(check));
  bool flag = false;
  queue<int> q;
  q.push(sx);
  check[sx] = true;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    if(x==ex) flag = true;
    for(auto k:a[x]) {
      if(check[k.to]==false&&k.cost>=m) {
        q.push(k.to);
        check[k.to] = true;
      }
    }
  }
  return flag;
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  int k = -1;
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    a[x].push_back(Edge(y,z));
    a[y].push_back(Edge(x,z));
    k = max(k,z);
  }
  int sx,ex;
  cin >> sx >> ex;
  int start = 0;
  int end = k;
  int maxi = -1;
  while(start<=end) {
    int mid = (start+end)/2;
    bool flag = bfs(sx,ex,mid);
    if(flag==true) {
      start = mid+1;
      maxi = max(maxi,mid);
    } else {
      end = mid-1;
    }
  }
  cout << maxi << '\n';
  return 0;
}