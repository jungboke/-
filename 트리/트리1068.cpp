#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int parent[51];
bool check[51];
int cnt = 0;
void dfs(int root,int n)
{
    bool flag = true;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==root)
        {
            flag = false;
            dfs(i,n);
        }
    }
    if(flag==true) cnt++;
}
int main()
{
    int n;
    cin >> n;
    int root = 0;
    for(int i=0;i<n;i++)
    {
        cin >> parent[i];
        if(parent[i]==-1) root = i;
    }
    int k;
    cin >> k;
    if(parent[k]==-1)
    {
        cout << 0 << '\n';
        return 0;
    }
    parent[k] = -1;
    dfs(root,n);
    cout << cnt << '\n';
    return 0;
}