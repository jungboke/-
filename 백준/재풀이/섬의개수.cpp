#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <queue>
#include <tuple>
using namespace std;
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};
bool check[51][51];
int main()
{
    while(true)
    {
        memset(check,false,sizeof(check));
        int m,n;
        cin >> m >> n;
        if(m==0&&n==0) break;
        vector<vector<int>> a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]==1&&check[i][j]==false)
                {
                    cnt++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    check[i][j] = true;
                    while(!q.empty())
                    {
                        int x,y;
                        tie(x,y) = q.front();
                        q.pop();
                        for(int i=0;i<8;i++)
                        {
                            int nx = x+dx[i];
                            int ny = y+dy[i];
                            if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny]==false)
                            {
                                if(a[nx][ny]==1)
                                {
                                    q.push(make_pair(nx,ny));
                                    check[nx][ny] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}