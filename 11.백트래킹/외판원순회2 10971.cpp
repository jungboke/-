/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[20][20];
bool check[20];
int mini = -1;
int N;
void dfs(int start,int sum,int x,int cnt)
{
    if(cnt==N-1)
    {
        if(a[start][x]!=0)
        {
            if(mini==-1||mini>sum+a[start][x]) mini = sum+a[start][x];
        }
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(check[i]==true||a[start][i]==0) continue;
        check[i] = true;
        dfs(i,sum+a[start][i],x,cnt+1);
        check[i] = false;
    }
}
int main()
{
    int n;
    cin >> n;
    N=n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        check[i] = true;
        dfs(i,0,i,0);
        check[i] = false;
    }
    cout << mini << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int a[11][11];
// bool check[11];
// int mini = 100000000;
// int N;
// void dfs(int start,int sum,int x,int cnt)
// {
//     if(cnt==N-1)
//     {
//         if(a[start][x]!=0)
//         {
//             if(mini==-1||mini>sum+a[start][x]) mini = sum+a[start][x];
//         }
//         return;
//     }
//     for(int i=0;i<N;i++)
//     {
//         if(check[i]==true||a[start][i]==0) continue;
//         check[i] = true;
//         dfs(i,sum+a[start][i],x,cnt+1);
//         check[i] = false;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     N=n;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
//         check[i] = true;
//         dfs(i,0,i,0);
//         check[i] = false;
//     }
//     cout << mini << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[11][11];
bool check[11];
int N;
int mini = INF;
void dfs(int x, int t, int sum) {
  if(check[x]==true&&x==t) {
    bool flag = true;
    for(int i=0;i<N;i++) {
      if(check[i]==false) flag = false;
    }
    if(flag==true) mini = min(mini,sum);
    return;
  }
  check[x] = true;
  for(int i=0;i<N;i++) {
    if(x==i) continue;
    if(a[x][i]!=0) {
      if(i==t||check[i]==false) {
        dfs(i,t,sum+a[x][i]);
      }
    }
  }
  check[x] = false;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  for(int i=0;i<n;i++) {
    dfs(i,i,0);
  }
  cout << mini << '\n';
  return 0;
}
