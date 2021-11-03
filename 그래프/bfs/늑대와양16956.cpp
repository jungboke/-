#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <string.h>
#include <tuple>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
char a[501][501];
int dist[501][501];
int N,M;
vector<pair<int,int>> wolf;
bool bfs()
{
    memset(dist,-1,sizeof(dist));
    queue<pair<int,int>> q;
    for(auto k : wolf)
    {
        dist[k.first][k.second] = 0;
        q.push(k);
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
            if(nx>=0&&nx<N&&ny>=0&&ny<M&&dist[nx][ny]==-1)
            {
                if(a[nx][ny]!='D')
                {
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        } 
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(a[i][j]=='S'&&dist[i][j]!=-1) return false;
        }
    }
    return true;
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
            if(a[i][j]=='W') wolf.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!='S') continue;
            for(int k=0;k<4;k++)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<m)
                {
                    if(a[nx][ny]=='.')
                    {
                        a[nx][ny] = 'D';
                    }
                }
            }
        }
    }
    if(bfs()==true)
    {
        cout << 1 << '\n';
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }
    }
    else
    {
        cout << 0 << '\n';  
    }
    return 0;
}
/*
    굳이 bfs로 조사할게아니라 주변모두를 울타리로 막을수 있으면 접근불가해서 무조건 1,
    주변에 바로 W가 있으면 울타리를 칠수 없으므로 무조건 0임.
*/