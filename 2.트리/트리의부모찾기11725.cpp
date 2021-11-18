#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> a[100001];
int parent[100001];
void dfs(int num,int before)
{
    parent[num] = before;
    for(int k : a[num])
    {
        if(parent[k]==0)
        {
            dfs(k,num);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=2;i<=n;i++)
    {
        cout << parent[i] << '\n';
    }
    return 0;
}