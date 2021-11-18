#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int a[101][101][101];
int check[101][101][101];
int main()
{
    memset(check,-1,sizeof(check));
    int n,m,h;
    cin >> m >> n >> h;
    queue<tuple<int,int,int>> q;
    for(int z=0;z<h;z++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j][z];
                if(a[i][j][z]==1)
                {
                    q.push(make_tuple(i,j,z));
                    check[i][j][z] = 0;
                }
                else if(a[i][j][z]==-1)
                {
                    check[i][j][z] = 0;
                }
            }
        }
    }
    while(!q.empty())
    {
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny][z]==-1)
            {
                if(a[nx][ny][z]==0)
                {
                    q.push(make_tuple(nx,ny,z));
                    check[nx][ny][z] = check[x][y][z] + 1;
                }
            }
        }
        if(z-1>=0&&check[x][y][z-1]==-1&&a[x][y][z-1]==0)
        {
            q.push(make_tuple(x,y,z-1));
            check[x][y][z-1] = check[x][y][z] + 1;
        }
        if(z+1<h&&check[x][y][z+1]==-1&&a[x][y][z+1]==0)
        {
            q.push(make_tuple(x,y,z+1));
            check[x][y][z+1] = check[x][y][z] + 1;
        }
    }
    int cnt = 0;
    for(int z=0;z<h;z++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(check[i][j][z]==-1)
                {
                    cout << -1 << '\n';
                    return 0;    
                }
                if(cnt<check[i][j][z]) cnt = check[i][j][z];
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
//tuple사용을 통한 3차원 구현. + get<0>(personInfo),get<1>(personInfo),get<2>(personInfo)