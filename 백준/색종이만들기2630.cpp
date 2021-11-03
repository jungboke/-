#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[150][150];
int white = 0;
int blue = 0;
void dfs(int x,int y,int n)
{
    bool flag = true;
    for(int i=x;i<x+n;i++)
    {
        for(int j=y;j<y+n;j++)
        {
            if(a[i][j]!=a[x][y])
            {
                flag = false;
                break;
            }
        }
    }
    if(flag==false)
    {
        dfs(x,y,n/2);
        dfs(x,y+n/2,n/2);
        dfs(x+n/2,y,n/2);
        dfs(x+n/2,y+n/2,n/2);
    }
    else
    {
        if(a[x][y]==1)
        {
            blue+=1;
        }
        else
        {
            white+=1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(0,0,n);
    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}