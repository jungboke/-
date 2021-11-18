#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};
void change(vector<vector<char>> &color,vector<vector<char>> &a)
{
    int n = color.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]=='*') color[i][j] = '*';
        }
    }
}
char go(int x,int y,vector<vector<char>> a)
{
    int n = a.size();
    int cnt = 0;
    for(int i=0;i<8;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n)
        {
            if(a[nx][ny]=='*') cnt++;
        }
    }
    char result = cnt+48;
    return result;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n,'0'));
    vector<vector<char>> color(n,vector<char>(n,'0'));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<n;j++)
        {
            a[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<n;j++)
        {
            color[i][j] = temp[j];
        }
    }
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(color[i][j]=='x')
            {
                color[i][j] = go(i,j,a);
                if(a[i][j]=='*')
                {
                    flag = true;
                }
            }
        }
    }
    if(flag==true) change(color,a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << color[i][j];
        }
        cout << '\n';
    }
    return 0;
}