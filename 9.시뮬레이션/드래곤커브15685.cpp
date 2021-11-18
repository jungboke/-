#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int a[101][101];
vector<int> curve(int w,int cnt)
{
    vector<int> temp;
    temp.push_back(w);
    for(int i=0;i<cnt;i++)
    {
        for(int j=temp.size()-1;j>=0;j--)
        {
            temp.push_back((temp[j]+1)%4);
        }
    }
    return temp;    
}
void make(int x,int y,vector<int> temp)
{
    a[x][y] = 1;
    for(int i=0;i<temp.size();i++)
    {
        int w = temp[i];
        x = x+dx[w];
        y = y+dy[w];
        a[x][y] = 1;
    }
}
int count()
{
    int cnt = 0;
    for(int i=0;i<101;i++)
    {
        for(int j=0;j<101;j++)
        {
            if(i+1<101&&j+1<101)
            {
                if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1)
                    cnt++;
            }
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x,y,w,cnt;
        cin >> x >> y >> w >> cnt;
        vector<int> temp;
        temp = curve(w,cnt);
        make(y,x,temp);
    }
    cout << count() << '\n';
    return 0;
}
/*
    dragon curve가 만들어지는 규칙을 알아내기만하면 간단히 풀수 있음.
*/