#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
bool check1[101][101];
void bfs(vector<vector<int>> &a)
{
    memset(check1,false,sizeof(check1));
    int n = a.size();
    int m = a[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    check1[0][0] = true;
    a[0][0] = 2;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&check1[nx][ny]==false)
            {
                if(a[nx][ny]==0)
                {
                    q.push(make_pair(nx,ny));
                    check1[nx][ny] = true;
                    a[nx][ny] = 2;
                }
            }
        }
    }
}
bool check(vector<vector<int>> a,int x,int y)
{
    int n = a.size();
    int m = a[0].size();
    bool flag = false;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m)
        {
            if(a[nx][ny]==2)
            {
                flag = true;
                break;
            }
        }
    }
    return flag;
}
int checksize(vector<vector<int>> a)
{
    int n = a.size();
    int m = a[0].size();
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1) cnt++;
        }
    }
    return cnt;
}
void change(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a = a;
    bfs(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==1)
            {
                if(check(a,i,j)==true)
                {
                    tmp_a[i][j] = 0;
                }
            }
        }
    }
    a = tmp_a;
} 
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    int cnt = 0;
    int last = 0;
    while(true)
    {
        if(checksize(a)==0) break;
        last = checksize(a);
        change(a);
        cnt++;
    }
    cout << cnt << '\n';
    cout << last << '\n';
    return 0;
}