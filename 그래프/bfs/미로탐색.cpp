#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dist[101][101];
int main(){

    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j] - 48;
        }
    }
    
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&dist[nx][ny]==0)
            {
                if(a[nx][ny]!=0)
                {
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
        }
    }
    cout << dist[n-1][m-1] << '\n';
    return 0;
}