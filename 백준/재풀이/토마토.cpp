#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dist[1001][1001];
int main()
{
    int m,n;
    cin >> m >> n;
    vector<vector<int>> a(n,vector<int>(m,0));
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==1)
            {
                dist[i][j] = 0;
                q.push(make_pair(i,j));
            }
            else if(a[i][j]==-1)
            {
                dist[i][j] = 0;
            }
        }
    }
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==-1)
            {
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[x][y]+1;
            }
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j]==-1)
            {
                cout << -1 << '\n';
                return 0;
            }
            if(maxi<dist[i][j]) maxi = dist[i][j];
        }
    }
    cout << maxi << '\n'; 
    return 0;
}