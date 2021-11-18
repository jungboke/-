/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a[n][n]; // 0:질량 1:속도 2:방향
    vector<vector<int>> b[n][n];
    vector<pair<int,int>> result;
    for(int i=0;i<m;i++)
    {
        int x,y,c,d,e;
        cin >> x >> y >> c >> d >> e;
        vector<int> temp;
        temp.push_back(c); temp.push_back(d); temp.push_back(e);
        a[x-1][y-1].push_back(temp);
        result.push_back(make_pair(x-1,y-1));
    }
    while(k--)
    {
        for(auto k : result)
        {
            int i = k.first;
            int j = k.second;
            int t = a[i][j].size();
            while(t--)
            {
                vector<int> temp = a[i][j][0];
                a[i][j].erase(a[i][j].begin());
                int nx = i+temp[1]*dx[temp[2]];
                int ny = j+temp[1]*dy[temp[2]];
                if(nx<0)
                {
                    while(nx<0) nx+=n;
                }
                else if(nx>=n) nx = nx%n;

                if(ny<0)
                {
                    while(ny<0) ny+=n;
                }
                else if(ny>=n) ny = ny%n;
                
                b[nx][ny].push_back(temp);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                while(!b[i][j].empty())
                {
                    vector<int> temp = b[i][j][0];
                    b[i][j].erase(b[i][j].begin());
                    a[i][j].push_back(temp);
                }
            }
        }
        result.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j].size()>0) result.push_back(make_pair(i,j));
                if(a[i][j].size()>1)
                {
                    double weight_sum = 0;
                    double speed_sum = 0;
                    int cnt = a[i][j].size();
                    int odd = 0;
                    int even = 0;
                    int where = -1; // 1 0246 2 1357
                    for(int k=0;k<a[i][j].size();k++)
                    {
                        if(a[i][j][k][2]%2==1) odd++;
                        else even++;
                    }
                    if(odd==0||even==0) where = 0;
                    else where = 1;
                    while(!a[i][j].empty())
                    {
                        vector<int> temp = a[i][j][0];
                        a[i][j].erase(a[i][j].begin());
                        weight_sum += temp[0];
                        speed_sum += temp[1];
                    }
                    for(int k=0;k<4;k++)
                    {
                        vector<int> temp;
                        temp.push_back(floor(weight_sum/5));
                        if(floor(weight_sum/5)==0) continue;
                        temp.push_back(floor(speed_sum/cnt));
                        temp.push_back(2*k+where);
                        a[i][j].push_back(temp);
                    }
                }
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<a[i][j].size();k++)
            {
                sum += a[i][j][k][0]; 
            }
        }
    }
    cout << sum << '\n';
    return 0;
}
/* 
    dx,dy를 바꿔서 생각했음,배열 index초과시 다시 배열안으로 들어올수 있도록 처리,
    a배열과 똑같은 b배열을 추가하여 이동하는 배열을 b배열에 저장후 모든 이동처리후에 b배열에서 이동된
    배열 다시 a로 복사.이렇게 안하면 이동처리중에 값이 추가되서 실패함, floor()기호 알아둬야함(아래L).
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
struct Fireball
{
    int x,y,m,s,d; // m 질량 s속력 d방향
};
vector<Fireball> a[51][51];
vector<Fireball> fireball;
void move(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j].clear();
        }
    }
    for(int i=0;i<fireball.size();i++)
    {
        Fireball temp = fireball[i];
        int x = temp.x;
        int y = temp.y;
        int m = temp.m;
        int s = temp.s;
        int d = temp.d;
        int nx = x+s*dx[d];
        int ny = y+s*dy[d];
        while(nx>=n) nx-=n;
        while(nx<0) nx+=n;
        while(ny>=n) ny-=n;
        while(ny<0) ny+=n;
        a[nx][ny].push_back({nx,ny,m,s,d});
    }
    
}
void sum(int n)
{
    vector<Fireball> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j].size()==0) continue;
            else if(a[i][j].size()==1)
            {
                temp.push_back(a[i][j][0]);
                continue;
            }
            int msum = 0;
            int ssum = 0;
            int odd = 0;
            int even = 0;
            for(int k=0;k<a[i][j].size();k++)
            {
                msum += a[i][j][k].m;
                ssum += a[i][j][k].s;
                if(a[i][j][k].d%2==1) odd++;
                else even++;
            }
            msum /= 5;
            ssum /= a[i][j].size();
            if(msum==0) continue;
            if(odd==0||even==0)
            {
                for(int z=0;z<4;z++)
                {
                    temp.push_back({i,j,msum,ssum,2*z});
                }
            }
            else
            {
                for(int z=0;z<4;z++)
                {
                    temp.push_back({i,j,msum,ssum,2*z+1});
                }
            }
        }
    }
    fireball = temp;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
        int x,y,b,c,d;
        cin >> x >> y >> b >> c >> d;
        Fireball temp;
        temp.x = x-1; temp.y = y-1; temp.m = b; temp.s = c; temp.d = d;
        a[x-1][y-1].push_back(temp);
        fireball.push_back(temp);
    }
    while(k--)
    {
        move(n);
        sum(n);
    }
    int answer = 0;
    for(int i=0;i<fireball.size();i++)
    {
        answer += fireball[i].m;
    }
    cout << answer << '\n';
    return 0;
}






















