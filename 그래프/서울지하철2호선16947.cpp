/*
#include <algorithm>
#include <vector>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
vector<int> a[3001];
int check[3001];
int dist[3001];
int dfs(int num,int back)
{
    if(check[num] == 1)
    {
        return num;
    }
    check[num] = 1;
    for(int k : a[num])
    {
        if(k==back) continue;
        int m = dfs(k,num);
        if(m==-2) return -2;
        if(m>=1)
        {
            check[num] = 2;
            if(m==num) return -2;
            else return m; 
        }
    }
    return -1;
}
int main(){

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==2)
        {
            q.push(i);
            dist[i] = 0;
        }
        else dist[i] = -1; 
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int k : a[x])
        {
            if(dist[k] == -1)
            {
                q.push(k);
                dist[k] = dist[x] + 1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}
// 반환형int 재귀함수 구현, 그래프에서의 사이클 탐색, 다중 시작점에서의 bfs거리 계산
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
vector<int> a[3001];
int check[3001];
int dist[3001];
int dfs(int num,int back)
{
    if(check[num]==1)
    {
        return num;
    }
    check[num] = 1;
    for(auto k : a[num])
    {
        if(k==back) continue;
        int m = dfs(k,num);
        if(m==-1) return -1;
        if(m==-2) continue;
        if(num!=m)
        {
            check[num] = 2;
            return m;
        }
        else
        {
            check[num] = 2;
            return -1;
        }
    }
    return -2;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,0);
    queue<int> q;
    memset(dist,-1,sizeof(dist));
    for(int i=1;i<=n;i++)
    {
        if(check[i]==2)
        {
            q.push(i);
            dist[i] = 0;
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(auto k:a[x])
        {
            if(dist[k]==-1)
            {
                q.push(k);
                dist[k] = dist[x]+1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << dist[i] << ' ';
    }
    cout << '\n';
    return 0;
}
// 반환형있는 재귀함수인데 최종반환형없게해서 dfs도중 마지막에서 튕겨져나올때 오류발생함.
// 반환형 재귀함수는 최대한 마지막 튕길때 오류발생 고려하기.