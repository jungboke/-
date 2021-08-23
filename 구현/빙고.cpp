#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[30];
void change(int num,vector<vector<int>> a,vector<vector<int>> &color)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]==num)
            {
                color[i][j] = 1;
            }
        }
    }
}
bool bingo(vector<vector<int>> color)
{
    int result = 0;
    for(int i=0;i<5;i++)
    {
        int cnt = 0;
        for(int j=0;j<5;j++)
        {
            if(color[i][j]==1) cnt++;
        }
        if(cnt==5) result++;
    }
    for(int j=0;j<5;j++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            if(color[i][j]==1) cnt++;
        }
        if(cnt==5) result++;
    }
    for(int m=0;m<=8;m++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(i+j==m&&color[i][j]==1) cnt++;
            }
        }
        if(cnt==5) result++;
    }
    for(int m=0;m<=8;m++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(j-i+4==m&&color[i][j]==1) cnt++;
            }
        }
        if(cnt==5) result++;
    }
    if(result>=3) return true;
    else return false;
}
int main()
{
    vector<vector<int>> a(5,vector<int>(5,0));
    vector<vector<int>> color(5,vector<int>(5,0));
    vector<vector<int>> call(5,vector<int>(5,0));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> call[i][j];
        }
    }
    int cnt = 0;
    bool flag = true;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cnt++;
            change(call[i][j],a,color);
            if(bingo(color)==true)
            {
                flag = false;
                break;
            }
        }
        if(flag==false) break;
    }
    cout << cnt << '\n';
    return 0;
}