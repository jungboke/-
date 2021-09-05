#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {0,-1,-1,-1,0,1,1,1};
int dy[] = {-1,-1,0,1,1,1,0,-1};
void move(vector<vector<int>> &b,int num,int how)
{
    int n = b.size();
    vector<vector<int>> tmp_b(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==1)
            {
                int nx = i+dx[num]*how;
                int ny = j+dy[num]*how;
                while(nx<0) nx+=n;
                while(nx>=n) nx-=n;
                while(ny<0) ny+=n;
                while(ny>=n) ny-=n;
                tmp_b[nx][ny] = 1;
                
            }
        }
    }
    b = tmp_b;
}
void rain(vector<vector<int>> &a,vector<vector<int>> b)
{
    int n = a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==1) a[i][j]++;
            else continue;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(b[i][j]==1)
            {
                for(int k=1;k<8;k+=2)
                {
                    int ux = i+dx[k];
                    int uy = j+dy[k];
                    if(ux>=0&&ux<n&&uy>=0&&uy<n)
                    {
                        if(a[ux][uy]>0) a[i][j]++;
                    }
                }
            }
        }
    }
}
void make(vector<vector<int>> &a,vector<vector<int>> &b)
{
    int n = a.size();
    vector<vector<int>> tmp_b(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]>=2&&b[i][j]!=1)
            {
                tmp_b[i][j] = 1;
                a[i][j] -= 2;
            }
        }
    }
    b = tmp_b;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<int>> b(n,vector<int>(n,0));
    b[n-2][0] = 1; b[n-2][1] = 1; b[n-1][0] = 1; b[n-1][1] = 1;
    for(int i=0;i<m;i++)
    {
        int num,how;
        cin >> num >> how;
        num-=1;
        move(b,num,how);
        rain(a,b);
        make(a,b);
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sum += a[i][j];
        }
    }
    cout << sum << '\n';   
    return 0;
}
/*
 비가 전체내린후에 물복사버그를 진행하는것과 비가 내리는 도중 물복사 버그를 진행시키는 것이
 다른것처럼 진행순서 잘확인하기!
*/