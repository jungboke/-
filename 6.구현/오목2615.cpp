/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;
pair<int,int> check(vector<vector<int>> a)
{
    int fx = -1;
    int fy = -1;
    // 가로체크
    for(int i=0;i<19;i++)
    {
        int cnt = 1;
        for(int j=0;j<18;j++)
        {
            if(a[i][j]==a[i][j+1]) cnt++;
            else cnt = 1;

            if(a[i][j]!=0&&cnt==5)
            {
                if(j+2<19)
                {
                    if(a[i][j+1]==a[i][j+2]) continue;
                }
                fx = i;
                fy = j-3;
            }
        }
    }
    // 세로체크
    for(int j=0;j<19;j++)
    {
        int cnt = 1;
        for(int i=0;i<18;i++)
        {
            if(a[i][j]==a[i+1][j]) cnt++;
            else cnt = 1;

            if(a[i][j]!=0&&cnt==5)
            {
                if(i+2<19)
                {
                    if(a[i+1][j]==a[i+2][j]) continue;
                }
                fx = i-3;
                fy = j;
            }
        }
    }
    // 우상향대각 체크
    for(int m=0;m<=36;m++)
    {
        int cnt = 1;
        int last = -1;
        for(int i=0;i<19;i++)
        {
            for(int j=0;j<19;j++)
            {
                if(i+j==m)
                {
                    if(a[i][j]==last) cnt++;
                    else cnt = 1;
                    last = a[i][j];

                    if(a[i][j]!=0&&cnt==5)
                    {
                        if(i+1<19&&j-1>=0)
                        {
                            if(a[i][j]==a[i+1][j-1]) continue;
                        }
                        fx = i;
                        fy = j;
                    }
                }
            }
        }
    }
    // 우하향대각 체크
    for(int m=0;m<=36;m++)
    {
        int cnt = 1;
        int last = -1;
        for(int i=0;i<19;i++)
        {
            for(int j=0;j<19;j++)
            {
                if(j-i+18==m)
                {
                    if(a[i][j]==last) cnt++;
                    else cnt = 1;
                    last = a[i][j];

                    if(a[i][j]!=0&&cnt==5)
                    {
                        if(i+1<19&&j+1<19)
                        {
                            if(a[i][j]==a[i+1][j+1]) continue;
                        }
                        fx = i-4;
                        fy = j-4;
                    }
                }
            }
        }
    }
    return make_pair(fx,fy);
}
int main()
{
    vector<vector<int>> a(19,vector<int>(19,0));
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            cin >> a[i][j];
        }
    }
    int x,y;
    tie(x,y) = check(a);
    if(x==-1&&y==-1) cout << 0 << '\n';
    else
    {
        cout << a[x][y] << '\n';
        cout << x+1 << ' ' << y+1 << '\n';
    }  
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int a[20][20];
int ax,ay;
int checkrow()
{
    for(int i=0;i<19;i++)
    {
        int cnt = 1;
        for(int j=1;j<19;j++)
        {
            if(a[i][j]!=a[i][j-1])
            {
                cnt = 1;
            }
            else cnt++;
            if(cnt==5&&a[i][j]!=0)
            {
                if(a[i][j]!=a[i][j+1])
                {
                    ax = i;
                    ay = j-4;
                    return a[i][j];
                }
                else continue; 
            }
        }
    }
    return 0;
}
int checkcol()
{
    for(int j=0;j<19;j++)
    {
        int cnt = 1;
        for(int i=1;i<19;i++)
        {
            if(a[i][j]!=a[i-1][j])
            {
                cnt = 1;
            }
            else cnt++;
            if(cnt==5&&a[i][j]!=0)
            {
                if(a[i][j]!=a[i+1][j])
                {
                    ax = i-4;
                    ay = j;
                    return a[i][j];
                }
                else continue; 
            }
        }
    }
    return 0;
}
int checkdig1()
{
    for(int m=0;m<=36;m++)
    {
        int cnt = 1;
        int last = -1;
        for(int i=0;i<19;i++)
        {
            for(int j=0;j<19;j++)
            {
                if(j-i+18==m)
                {
                    if(a[i][j]==last) cnt++;
                    else
                    {
                        cnt = 1;
                        last = a[i][j];
                    }
                    if(cnt==5&&a[i][j]!=0)
                    {
                        if(i+1>=0&&i+1<19&&j+1>=0&&j+1<19&&a[i+1][j+1]==last) continue;
                        else
                        {
                            ax = i-4;
                            ay = j-4;
                            return a[i][j];
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int checkdig2()
{
    for(int m=0;m<=36;m++)
    {
        int cnt = 1;
        int last = -1;
        for(int i=0;i<19;i++)
        {
            for(int j=0;j<19;j++)
            {
                if(i+j==m)
                {
                    if(a[i][j]==last) cnt++;
                    else
                    {
                        cnt = 1;
                        last = a[i][j];
                    }
                    if(cnt==5&&a[i][j]!=0)
                    {
                        if(i+1>=0&&i+1<19&&j-1>=0&&j-1<19&&a[i+1][j-1]==last) continue;
                        else
                        {
                            ax = i;
                            ay = j;
                            return a[i][j];
                        }
                    }
                }
            }
        }
    }
    return 0;
}
int main()
{
    for(int i=0;i<19;i++)
    {
        for(int j=0;j<19;j++)
        {
            cin >> a[i][j];
        }
    }
    int flag1 = checkcol();
    int flag2 = checkrow();
    int flag3 = checkdig1();
    int flag4 = checkdig2();
    if(flag1==1||flag2==1||flag3==1||flag4==1)
    {
        cout << 1 << '\n';
        cout << ax+1 << ' ' << ay+1 << '\n';
    }
    else if(flag1==2||flag2==2||flag3==2||flag4==2)
    {
        cout << 2 << '\n';
        cout << ax+1 << ' ' << ay+1 << '\n';
    }
    else cout << 0 << '\n';
    return 0;
}