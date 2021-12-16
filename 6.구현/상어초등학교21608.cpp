/*
    max조건이 2개인 경우를 해결해야함. 해당 문제에서는 주변 친구의 개수가 같은경우
    빈칸이 더 많은 쪽이 최대로 설정되어야 함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int main()
{
    int n;
    cin >> n;
    unordered_map<int,vector<int>> map1;
    vector<vector<int>> student;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<int> order;
    for(int i=0;i<pow(n,2);i++)
    {
        int a;
        cin >> a;
        order.push_back(a);
        for(int i=0;i<4;i++)
        {
            int k;
            cin >> k;
            map1[a].push_back(k);
        }
    }
    for(int m=0;m<order.size();m++)
    {
        int num = order[m];
        vector<int> temp = map1[num];
        int maxi = -1;
        int maxi2 = -1;
        int m_x = 0;
        int m_y = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]!=0) continue;
                int cnt1 = 0;
                int cnt2 = 0;
                int x,y;
                x=i;y=j;
                for(int k=0;k<4;k++)
                {
                    int nx = x+dx[k];
                    int ny = y+dy[k];
                    if(nx>=0&&nx<n&&ny>=0&&ny<n)
                    {
                        if(a[nx][ny]==0) cnt2++;
                        if(find(temp.begin(),temp.end(),a[nx][ny])!=temp.end()) cnt1++;
                    }
                }
                if(maxi<cnt1)
                {
                    m_x = x;
                    m_y = y;
                    maxi = cnt1;
                    maxi2 = cnt2;
                }
                else if(maxi==cnt1)
                {
                    if(maxi2<cnt2)
                    {
                        m_x = x;
                        m_y = y;
                        maxi = cnt1;
                        maxi2 = cnt2;
                    }
                }
            }
        }
        a[m_x][m_y] = num; 
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int num = a[i][j];
            vector<int> temp = map1[num];
            int cnt = 0;
            int x = i;
            int y = j;
            for(int k=0;k<4;k++)
            {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(nx>=0&&nx<n&&ny>=0&&ny<n)
                {
                    if(find(temp.begin(),temp.end(),a[nx][ny])!=temp.end()) cnt++;
                }
            }
            if(cnt==0) sum+=0;
            else if(cnt==1) sum+=1;
            else if(cnt==2) sum+=10;
            else if(cnt==3) sum+=100;
            else sum+=1000;
        }
    }
    
    cout << sum << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[21][21];
int N;
int near(int x,int y,vector<int> temp)
{
    int cnt = 0;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<N)
        {
            if(find(temp.begin(),temp.end(),a[nx][ny])!=temp.end())
            {
                cnt++;
            }
        }
    }
    return cnt;
}
int nearzero(int x,int y)
{
    int cnt = 0;
    for(int i=0;i<4;i++)
    {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<N&&ny>=0&&ny<N)
        {
            if(a[nx][ny]==0) cnt++;
        }
    }
    return cnt;
}
void insert(int x,vector<int> temp)
{
    int maxi = -1;
    int max_zero = -1;
    int mx = 0;
    int my = 0;
    int zero = 0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(a[i][j]==0)
            {
                int cnt = near(i,j,temp);
                int zero = nearzero(i,j);
                if(maxi<=cnt)
                {
                    if(maxi==cnt&&max_zero>=zero) continue;
                    maxi = cnt;
                    max_zero = zero;
                    mx = i;
                    my = j;
                }
            }
        }
    }
    a[mx][my] = x;    
}
int main()
{
    int n;
    cin >> n;
    N=n;
    unordered_map<int,vector<int>> map1;
    for(int i=0;i<pow(n,2);i++)
    {
        int x;
        cin >> x;
        vector<int> temp(4);
        for(int i=0;i<4;i++)
        {
            cin >> temp[i];
        }
        map1[x] = temp;
        insert(x,map1[x]);
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(near(i,j,map1[a[i][j]])==0) answer+=0;
            else if(near(i,j,map1[a[i][j]])==1) answer+=1;
            else if(near(i,j,map1[a[i][j]])==2) answer+=10;
            else if(near(i,j,map1[a[i][j]])==3) answer+=100;
            else if(near(i,j,map1[a[i][j]])==4) answer+=1000;
        }
    }
    cout << answer << '\n';
    return 0;
}