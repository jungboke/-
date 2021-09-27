#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dist[21][21];
int move(vector<vector<int>> &a,int &x,int &y,int size)
{
    int n = a.size();
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    dist[x][y] = 0;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&dist[nx][ny]==-1)
            {
                if(a[nx][ny]<=size)
                {
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y]+1;
                }
            }
        }
    }
    int mini = 99999999;
    int ex,ey;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0&&a[i][j]!=9&&a[i][j]<size&&dist[i][j]!=-1)
            {
                if(dist[i][j] < mini)
                {
                    mini = dist[i][j];
                    ex = i;
                    ey = j;
                }
            }
        }
    }
    if(mini==99999999) return -1;
    a[ex][ey] = 0;
    x = ex; y = ey;
    return dist[ex][ey];
}
int main()
{
    int n;
    cin >> n;
    int sx,sy;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==9)
            {
                a[i][j] = 0;
                sx = i;
                sy = j;
            }
        }
    }
    int size = 2;
    int cnt = 0;
    int eat = 0;
    while(true)
    {       
        int time = move(a,sx,sy,size);
        if(time==-1) break;
        cnt += time;
        eat += 1;
        if(eat==size)
        {
            size++;
            eat = 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}
/*
    상어가 최단거리의 물고기를 먹을수 있는 경우를 구하는데 예외처리를 못해 오래걸림.
*/