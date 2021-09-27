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