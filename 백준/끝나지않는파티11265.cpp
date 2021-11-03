#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dist[501][501];
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
            cin >> dist[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(dist[x][y]>z)
        {
            cout << "Stay here" << '\n';
        }
        else cout << "Enjoy other party" << '\n';
    }
    return 0;
}