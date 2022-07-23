#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1000000000
using namespace std;
int dist[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(dist[x][y]>z) dist[x][y] = z;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dist[i][j]==INF) cout << 0 << ' ';
            else cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}