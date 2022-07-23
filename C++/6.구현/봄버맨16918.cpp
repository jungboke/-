#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int dist[201][201];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dist,-1,sizeof(dist));
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<char>> a(n,vector<char>(m,'0'));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j];
            if(a[i][j]=='O') dist[i][j] = 1;
        }
    }
    int cnt = 1; 
    while(cnt<k)
    {
        cnt++;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dist[i][j]++;
                if(dist[i][j]==3)
                {
                    dist[i][j] = -1;
                    q.push(make_pair(i,j));
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
                if(nx>=0&&nx<n&&ny>=0&&ny<m)
                {
                    dist[nx][ny] = -1;    
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[i][j]==-1) cout << '.';
            else cout << 'O';
        }
        cout << '\n';
    }
    return 0;
}