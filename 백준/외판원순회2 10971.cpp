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