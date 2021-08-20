#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int dist[301][301];
int main(){

    int t;
    cin >> t;
    while(t--)
    {
        memset(dist,-1,sizeof(dist));
        int n;
        cin >> n;
        int a,b,c,d;
        cin >> a >> b;
        cin >> c >> d;
        vector<vector<int>> k(n,vector<int>(n,0));
        queue<pair<int,int>> q;
        q.push(make_pair(a,b));
        dist[a][b] = 0;
        while(!q.empty())
        {
            int x,y;
            tie(x,y) = q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&dist[nx][ny]==-1)
                {
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
        }
        cout << dist[c][d] << '\n';
    }
    return 0;
}