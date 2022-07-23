/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[32001];
int ind[32001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        ind[y] += 1;
    }
    priority_queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0) q.push(-i);
    }
    while(!q.empty())
    {
        int x = -q.top();
        q.pop();
        cout << x << ' ';
        for(int i=0;i<a[x].size();i++)
        {
            int y = a[x][i];
            ind[y] -= 1;
            if(ind[y]==0) q.push(-y);
        }
    }
    cout << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// vector<int> a[32001];
// int ind[32001];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         ind[y]++;
//     }
//     priority_queue<int> q;
//     for(int i=1;i<=n;i++)
//     {
//         if(ind[i]==0) q.push(-i);
//     }
//     while(!q.empty())
//     {
//         int x = -q.top();
//         q.pop();
//         cout << x << ' ';
//         for(auto k:a[x])
//         {
//             ind[k]--;
//             if(ind[k]==0) q.push(-k);
//         }
//     }
//     cout << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[32001];
int ind[32001];

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    ind[y]+=1;
  }
  priority_queue<int> pq;
  for(int i=1;i<=n;i++) {
    if(ind[i]==0) pq.push(-i);
  }
  while(!pq.empty()) {
    int x = -pq.top();
    pq.pop();
    cout << x << ' ';
    for(auto k:a[x]) {
      ind[k]-=1;
      if(ind[k]==0) {
        pq.push(-k);
      }
    }
  }
  return 0;
}
