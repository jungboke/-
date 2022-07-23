/*
  트리의 리프에 물이 다모이게 됨.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[500001];
bool check[500001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(11);
    int n;
    cin >> n;
    double m;
    cin >> m;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int cnt = 0;
    queue<int> q;
    q.push(1);
    check[1] = true;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        bool flag = false;
        for(int i=0;i<a[x].size();i++)
        {
            int next = a[x][i];
            if(check[next]==false)
            {
                flag = true;
                q.push(next);
                check[next] = true; 
            }
        }
        if(flag==false) cnt++;
    }
    cout << m/cnt << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;
// vector<int> a[500001];
// bool check[500001];
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.setf(ios::fixed);
//     cout.precision(10);
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<n-1;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[x].push_back(y);
//         a[y].push_back(x);
//     }
//     int cnt = 0;
//     queue<int> q;
//     q.push(1);
//     check[1] = true;
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         bool flag = true;
//         for(auto k:a[x])
//         {
//             if(check[k]==true) continue;
//             flag = false;
//             q.push(k);
//             check[k] = true;
//         }
//         if(flag==true) cnt++;
//     }
//     cout << (double)m/cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[500001];

int main(int argc, char const *argv[])
{
  cout.setf(ios::fixed);
  cout.precision(10);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n-1;i++) {
    int x,y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  int cnt = 0;
  for(int i=1;i<=n;i++) {
    if(a[i].size()==1) cnt+=1;
  }
  if(a[1].size()==1) cnt-=1;

  cout << (double)m/cnt << '\n';
  return 0;
}
