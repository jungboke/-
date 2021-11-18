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
