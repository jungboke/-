// 다음풀이에서는 bfs함수화, bfs할때마다 배열값 평균으로 맞춰주기
// 현재풀이는 bfs함수화안했고, bfs 전체를 진행시킨후 마지막에 한번에 평균화시킴, map에서 사이즈1인값도 바꿔주느라 시간초과.
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cmath>
#include <string.h>
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int check[51][51];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,L,R;
    cin >> n >> L >> R;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    int answer = 0;
    bool flag = true;
    while(flag==true)
    {
        answer++;
        flag = false;
        int idx = 1;
        memset(check,0,sizeof(check));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check[i][j]==0)
                {
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    check[i][j] = idx;
                    while(!q.empty())
                    {
                        int x,y;
                        tie(x,y) = q.front();
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int nx = x+dx[i];
                            int ny = y+dy[i];
                            if(nx>=0&&nx<n&&ny>=0&&ny<n&&check[nx][ny]==0)
                            {
                                if(abs(a[nx][ny]-a[x][y])>=L&&abs(a[nx][ny]-a[x][y])<=R)
                                {
                                    flag = true;
                                    q.push(make_pair(nx,ny));
                                    check[nx][ny] = idx;
                                }
                            }
                        }
                    }
                    idx++; 
                }
            }
        }
        if(flag==false) break;
        unordered_map<int,pair<int,int>> map1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                map1[check[i][j]].first += a[i][j];
                map1[check[i][j]].second++;
            }
        }
        
        for(auto k:map1)
        {
            if(k.second.second==1) continue;
            int sum = k.second.first/k.second.second;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(check[i][j]==k.first)
                    {
                        a[i][j] = sum;
                    }
                }
            }
        }
    }
    cout << answer-1 << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int a[51][51];
bool check[51][51];
int N,L,R;
int bfs(int x,int y)
{
    vector<pair<int,int>> temp;
    int sum = 0;
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    temp.push_back(make_pair(x,y));
    sum += a[x][y];
    check[x][y] = true;
    while(!q.empty())
    {
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<N&&check[nx][ny]==false)
            {
                int num1 = abs(a[nx][ny]-a[x][y]);
                if(num1>=L&&num1<=R)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = true;
                    temp.push_back(make_pair(nx,ny));
                    sum += a[nx][ny];
                }
            }
        }
    }
    if(temp.size()!=1)
    {
        sum /= temp.size();
        for(int i=0;i<temp.size();i++)
        {
            a[temp[i].first][temp[i].second] = sum;
        }
    }
    return temp.size();
}
int main()
{
    int n,l,r;
    cin >> n >> l >> r;
    N=n;L=l;R=r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    int day = 0;
    bool flag = true;
    while(flag==true)
    {
        memset(check,false,sizeof(check));
        flag = false;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(check[i][j]==false)
                {
                    int x = bfs(i,j);
                    if(x!=1)
                    {
                        flag = true;
                    }
                }
            }
        }
        if(flag==false) break;
        day++;
    }
    cout << day << '\n';
    return 0;
}