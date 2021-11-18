#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
void spread(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> b(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!=0&&a[i][j]!=-1)
            {
                for(int k=0;k<4;k++)
                {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&a[nx][ny]!=-1)
                    {
                        b[nx][ny] += a[i][j]/5;
                        b[i][j] -= a[i][j]/5;

                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j] += b[i][j];
        }
    }
}
void cycle(vector<vector<int>> &a,vector<pair<int,int>> puri)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> b(n,vector<int>(m,0));
    int upx = puri[0].first; int upy = puri[0].second;
    int downx = puri[1].first; int downy = puri[1].second;
    for(int j=1;j<m;j++)
    {
        b[upx][j] = a[upx][j-1];
        if(b[upx][j]==0) b[upx][j] = -1; 
    }
    for(int i=upx-1;i>=0;i--)
    {
        b[i][m-1] = a[i+1][m-1];
        if(b[i][m-1]==0) b[i][m-1] = -1;
    }
    for(int j=m-2;j>=0;j--)
    {
        b[0][j] = a[0][j+1];
        if(b[0][j]==0) b[0][j] = -1;
    }
    for(int i=1;i<upx;i++)
    {
        b[i][0] = a[i-1][0];
        if(b[i][0]==0) b[i][0] = -1;
    }
    //down
    for(int j=1;j<m;j++)
    {
        b[downx][j] = a[downx][j-1];
        if(b[downx][j]==0) b[downx][j] = -1; 
    }
    for(int i=downx+1;i<n;i++)
    {
        b[i][m-1] = a[i-1][m-1];
        if(b[i][m-1]==0) b[i][m-1] = -1;
    }
    for(int j=m-2;j>=0;j--)
    {
        b[n-1][j] = a[n-1][j+1];
        if(b[n-1][j]==0) b[n-1][j] = -1;
    }
    for(int i=n-2;i>downx;i--)
    {
        b[i][0] = a[i+1][0];
        if(b[i][0]==0) b[i][0] = -1;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]!=0) a[i][j] = b[i][j];
            if(b[i][j]==-1) a[i][j] = 0;
        }
    }
}
int main()

{
    int n,m,t;
    cin >> n >> m >> t;
    vector<vector<int>> a(n,vector<int>(m,0));
    vector<pair<int,int>> puri;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==-1) puri.push_back(make_pair(i,j));
        }
    }
    for(int i=0;i<t;i++)
    {
        spread(a);
        cycle(a,puri);
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            sum+=a[i][j];
        }
    }
    cout << sum+2 << '\n';
    return 0;
}
// 임시배열 생성(b)을 통한 spread구현과 막무가내의 cycle구현.