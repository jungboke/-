/*
    백트래킹 문제는 for문에서 전부 예외처리 되는 경우도 생각해주어야함. 위문제는
    모든 계란이 깨져있어 for문이 생략된 경우, dfs(x+1)이 동작하지 않아 멈춰버림. 
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[10][2];
bool check[10];
int N;
int maxi = 0;
void dfs(int x)
{
    if(x==N)
    {
        int cnt = 0;
        for(int i=0;i<N;i++)
        {
            if(check[i]==true) cnt++; 
        }
        maxi = max(maxi,cnt);
        return;
    }
    if(check[x]==true)
    {
        dfs(x+1);
        return;
    }
    bool flag = true;
    for(int i=0;i<N;i++)
    {    
        if(i==x||check[i]==true) continue;
        flag = false;
        a[i][0] = a[i][0] - a[x][1];
        a[x][0] = a[x][0] - a[i][1];
        if(a[i][0]<=0) check[i] = true;
        if(a[x][0]<=0) check[x] = true;
        dfs(x+1);
        a[i][0] = a[i][0] + a[x][1];
        a[x][0] = a[x][0] + a[i][1];
        if(a[i][0]>0) check[i] = false;
        if(a[x][0]>0) check[x] = false;
    }
    if(flag==true) dfs(N);
}
int main()
{
    int n;
    cin >> n;
    N=n;
    for(int i=0;i<n;i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    dfs(0);
    cout << maxi << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int maxi = 0;
int stat[10];
int weight[10];
bool check[10];
int N;
void dfs(int idx)
{
    if(idx==N)
    {
        int cnt = 0;
        for(int i=0;i<N;i++)
        {
            if(check[i]==true) cnt++;
        }
        maxi = max(maxi,cnt);
        return;
    }
    if(check[idx]==true)
    {
        dfs(idx+1);
        return;
    }
    bool flag = true;
    for(int i=0;i<N;i++)
    {
        if(i==idx||check[i]==true) continue;
        flag = false;
        stat[idx] = stat[idx] - weight[i];
        if(stat[idx]<=0) check[idx] = true;
        stat[i] = stat[i] - weight[idx];
        if(stat[i]<=0) check[i] = true;
        dfs(idx+1);
        stat[idx] = stat[idx] + weight[i];
        if(stat[idx]>0) check[idx] = false;
        stat[i] = stat[i] + weight[idx];
        if(stat[i]>0) check[i] = false;
    }
    if(flag==true) dfs(N);
}
int main()
{
    int n;
    cin >> n;
    N=n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        stat[i] = x;
        weight[i] = y;
    }
    dfs(0);
    cout << maxi << '\n';
    return 0;
}