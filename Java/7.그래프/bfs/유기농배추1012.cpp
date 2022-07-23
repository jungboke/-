#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
bool check[51][51];
int N,M;
void bfs(vector<vector<int>> &a,int x, int y)
{
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    check[x][y] = true;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&a[nx][ny]==1)
            {
                if(check[nx][ny]==false)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                }
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(check,false,sizeof(check));
        int n,m,k;
        cin >> n >> m >> k;
        N=n;M=m;
        vector<vector<int>> a(n,vector<int>(m,0));
        for(int i=0;i<k;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x][y] = 1;
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1&&check[i][j]==false)
                {
                    bfs(a,i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}