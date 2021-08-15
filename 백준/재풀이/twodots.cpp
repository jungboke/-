#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check[51][51];
int N,M;
vector<vector<int>> a(51,vector<int>(51,0));
bool dfs(int x,int y,int ix,int iy)
{
    if(check[x][y]==true)
    {
        return true;
    }
    check[x][y] = true;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx==ix&&ny==iy) continue;
        if(nx>=0&&nx<N&&ny>=0&&ny<M&&a[nx][ny]==a[x][y])
        {
            if(dfs(nx,ny,x,y)==true) return true;
        }
    }
    return false;
}
int main()
{
    int n,m;
    cin >> n >> m;
    N=n;M=m;
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(check[i][j]==false)
            {
                if(dfs(i,j,i,j)==true)
                {
                    cout << "Yes" << '\n';
                    return 0;
                }
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}