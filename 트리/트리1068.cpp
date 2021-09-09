/*
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
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int parent[51];
int answer = 0;
void go(int root,int n)
{
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(parent[i]==root)
        {
            flag = true;
            go(i,n);
        }
    }
    if(flag==false) answer++;
}
int main()
{
    int n;
    cin >> n;
    int root = 0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==-1) root = i; 
        parent[i] = x;
    }
    int m;
    cin >> m;
    if(parent[m]==-1)
    {
        cout << 0 << '\n';
        return 0;
    }
    parent[m] = -1;
    go(root,n);
    cout << answer << '\n';
    return 0;
}




















