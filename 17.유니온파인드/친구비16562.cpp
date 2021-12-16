/*
    분리 집합.
    한 집합내에서 가장 적은 비용의 친구를 구하면 전부 친구됨.
    분리집합을 할때 Union(x,y)나 Union(y,x)는 차이가 없는듯함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#define rank _rank
using namespace std;
int item[10001];
int parent[10001];
int rank[10001];
vector<int> a[10001];
int Find(int x)
{
    if(parent[x]==x) return x;
    else return parent[x] = Find(parent[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(rank[y]>rank[x]) swap(x,y);
    parent[y] = x;
    if(rank[y]==rank[x]) rank[x]++;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=1;i<=n;i++) cin >> item[i];
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }
    for(int i=1;i<=n;i++)
    {
        int x = Find(i);
        a[x].push_back(item[i]);
    }
    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i].empty()) continue;
        sum += *min_element(a[i].begin(),a[i].end());
    }
    if(sum>k) cout << "Oh no" << '\n';
    else cout << sum << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
#define rank _rank
using namespace std;
int parent[10001];
int rank[10001];
int Find(int x)
{
    if(x==parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(rank[y]>rank[x]) swap(x,y);
    parent[y] = x;
    if(rank[y]==rank[x]) rank[x]++;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }
    vector<vector<int>> result(n+1);
    for(int i=1;i<=n;i++)
    {
        result[Find(i)].push_back(a[i]);
    }
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(result[i].empty()) continue;
        answer += *min_element(result[i].begin(),result[i].end());
    }
    if(answer<=k) cout << answer << '\n';
    else cout << "Oh no" << '\n';
    return 0;
}