/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check[51][51];
int dist[51][51];
int N,M;
bool dfs(int x, int y,int cnt,vector<vector<char>> a)
{
    if(check[x][y]==true) return (cnt-dist[x][y] >= 4);
    check[x][y] = true;
    dist[x][y] = cnt;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<M)
        {
            if(a[nx][ny]==a[x][y])
            {
                if(dfs(nx,ny,cnt+1,a)) return true;
            }
        }
    }
    return false;
}
int main() {

    int n,m;
    cin >> n >> m;
    N=n; M=m;
    vector<vector<char>> a(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j] - 48;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(check[i][j]==true) continue;
            memset(dist,0,sizeof(dist));
            if(dfs(i,j,0,a)==true)
            {
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
// 사이클 만드는지 여부를 확인하는 문제, bool형 dfs, 왔던곳 다시방문할수 있는 dfs
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check[51][51];
char a[51][51];
int N,M;
bool dfs(int x,int y,int bx,int by)
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
        if(nx==bx&&ny==by) continue;
        if(nx>=0&&nx<N&&ny>=0&&ny<M)
        {
            if(a[nx][ny]==a[x][y])
            {
                if(dfs(nx,ny,x,y)==true) return true;
            }
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






















