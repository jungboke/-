#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
int N,M,C;
vector<int> result;
bool checkenemy(vector<vector<int>> a)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(a[i][j]==1) return true;
        }
    }
    return false;        
}
void shot(vector<vector<int>> &a,int &cnt)
{
    set<pair<int,int>> result;
    for(int z=0;z<M;z++)
    {
        if(a[N][z]==0) continue;
        int x = N; int y = z;
        int nx=-1;int ny=-1;
        int mini = 100000000;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(a[i][j]==0) continue;
                if(abs(x-i)+abs(y-j)<=mini)
                {
                    if(abs(x-i)+abs(y-j)==mini&&j>=ny) continue;
                    mini = abs(x-i)+abs(y-j); 
                    nx = i;
                    ny = j;
                }
            }
        }
        if(mini<=C) result.insert(make_pair(nx,ny));
    }
    cnt+=result.size();
    for(auto k:result)
    {
        int x = k.first;
        int y = k.second;
        a[x][y] = 0;
    }
}
void move(vector<vector<int>> &a)
{
    vector<vector<int>> temp = a;
    for(int j=0;j<M;j++) temp[0][j] = 0;
    for(int i=1;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            temp[i][j] = a[i-1][j];
        }
    }
    a = temp;
}
int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    N=n;M=m;C=c;
    vector<vector<int>> a(n+1,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> perm;
    for(int i=0;i<3;i++) perm.push_back(2);
    for(int i=0;i<m-3;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<vector<int>> tmp_a = a;
        for(int j=0;j<m;j++) tmp_a[n][j] = perm[j];
        int cnt = 0;
        while(true)
        {
            if(checkenemy(tmp_a)==false)
            {
                result.push_back(cnt);
                break;
            }
            shot(tmp_a,cnt);
            move(tmp_a);
        }
    }while(next_permutation(perm.begin(),perm.end()));
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
/*
    시뮬레이션 문제는 빨리풀면서 최대한 구현에 실수가 없도록 하는게 중요한듯.
    같은 거리의 적이 많을경우, 가장 왼쪽이라는 조건을 실수해서 오래걸림.
*/