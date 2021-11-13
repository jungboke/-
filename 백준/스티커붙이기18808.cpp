#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a(m,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            tmp_a[j][n-1-i] = a[i][j];
        }
    }
    a.resize(m,vector<int>(n,0));
    a = tmp_a;
}
void change(vector<vector<int>> &a,vector<vector<int>> b)
{
    int rcnt = 4;
    int n = a.size();
    int m = a[0].size();
    for(int i=0;i<3;i++) rotate(b);
    while(rcnt--)
    {
        rotate(b);
        vector<pair<int,int>> b2;
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                if(b[i][j]==1) b2.push_back(make_pair(i,j));
            }
        }
        //for(int i=0;i<b2.size();i++) cout << b2[i].first << b2[i].second << '\n';
        int n2 = b.size();
        int m2 = b[0].size();
        for(int i=0;i<=n-n2;i++)
        {
            for(int j=0;j<=m-m2;j++)
            {
                bool flag = true;
                for(int k=0;k<b2.size();k++)
                {
                    int nx = b2[k].first+i;
                    int ny = b2[k].second+j;
                    if(a[nx][ny]==1)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag==true)
                {
                    for(int k=0;k<b2.size();k++)
                    {
                        int x = b2[k].first+i;
                        int y = b2[k].second+j;
                        a[x][y] = 1;
                    }
                    return;
                }
            }
        }
    }
    return;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<k;i++)
    {
        int n2,m2;
        cin >> n2 >> m2;
        vector<vector<int>> b(n2,vector<int>(m2,0));
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<m2;j++)
            {
                cin >> b[i][j];
            }
        }
        change(a,b);
        /*
        rotate(b);
        for(int i=0;i<m2;i++)
        {
            for(int j=0;j<n2;j++)
            {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }
        return 0;
        */
    }
     int answer = 0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(a[i][j]==1) answer++;
         }
     }
     cout << answer << '\n';
    return 0;
}
/*
    직사각형도 정사각형과 같이 90도 rotation가능, 단, N에 유의하고, vector<vector<int>>를 복사
    할 경우, 크기가 다르면 안됨. resize()를 통해 크기 변환후 복사하기.
    Rotate 알고리즘과 배열내 소배열 이동 알고리즘이 필요한 문제.
*/