/*
    연결그래프인지 비연결그래프인지 알수없는 상황에서 주어진 정점들이 연결되어 있나 확인하기 위해서는
    분리집합을 만들어서 모든 Find(i)가 같은지 확인하면 됨.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#define rank _rank
using namespace std;
int rank[201];
int parent[201];
int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = Find(parent[x]);
}
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) swap(x,y);
    parent[y] = x;
    if(rank[x]==rank[y]) rank[x]++;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;
            cin >> x;
            if(x==1)
            {
                Union(i,j);
            }
        }
    }
    vector<int> a(m);
    for(int i=0;i<m;i++) cin >> a[i];
    bool flag = true;
    for(int i=0;i<m-1;i++)
    {
        if(Find(a[i])!=Find(a[i+1]))
        {
            flag = false;
            break;
        }
    }
    if(flag==true) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// #define rank _rank
// using namespace std;
// int parent[201];
// int rank[201];
// int Find(int x)
// {
//     if(x==parent[x]) return x;
//     else return parent[x] = Find(parent[x]);
// }
// void Union(int x,int y)
// {
//     x = Find(x);
//     y = Find(y);
//     if(x==y) return;
//     if(rank[y]>rank[x]) swap(x,y);
//     parent[y] = x;
//     if(rank[y]==rank[x]) rank[x]++;
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=1;i<=n;i++) parent[i] = i;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             int x;
//             cin >> x;
//             if(x==1) Union(i,j); 
//         }
//     }
//     vector<int> temp(m);
//     bool flag = true;
//     for(int i=0;i<m;i++)
//     {   
//         cin >> temp[i];
//     }
//     for(int i=1;i<m;i++)
//     {
//         if(Find(temp[i])!=Find(temp[i-1])) flag = false;  
//     }
//     if(flag==true) cout << "YES" << '\n';
//     else cout << "NO" << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define rank _rank
using namespace std;
int parent[201];
int rank[201];

int Find(int x) {
  if(parent[x]==x) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x==y) return;
  if(rank[x]<rank[y]) swap(x,y);
  parent[y] = x;
  if(rank[x]==rank[y]) rank[x]+=1;
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) {
    parent[i] = i;
  }
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      int x;
      cin >> x;
      if(x==0||i>=j) continue;
      Union(i,j);
    }
  }
  vector<int> temp(m);
  bool flag = true;
  for(int i=0;i<m;i++) {
    cin >> temp[i];
  }
  for(int i=1;i<m;i++) {
    if(Find(temp[i])!=Find(temp[i-1])) flag = false;
  }

  if(flag==true) cout << "YES" << '\n';
  else cout << "NO" << '\n';
  return 0;
}
