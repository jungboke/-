#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second) return (a.first<b.first);
    return (a.second<b.second);
}
void funcR(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int maxi = 0;
    vector<vector<int>> tmp_a(n);
    for(int c=0;c<n;c++)
    {
        unordered_map<int,int> map1;
        for(int i=0;i<a[c].size();i++)
        {
            if(a[c][i]==0) continue;
            map1[a[c][i]]++;
        }
        vector<pair<int,int>> temp;
        temp.assign(map1.begin(),map1.end());
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<temp.size();i++)
        {
            tmp_a[c].push_back(temp[i].first);
            tmp_a[c].push_back(temp[i].second);
            if(i==49) break;
        }
        if(maxi<tmp_a[c].size()) maxi = tmp_a[c].size();
    }
    for(int c=0;c<n;c++)
    {
        int cnt = maxi - tmp_a[c].size();
        for(int i=0;i<cnt;i++) tmp_a[c].push_back(0);
    }
    a.resize(tmp_a.size(),vector<int>(tmp_a[0].size(),0));
    a = tmp_a;
}
void funcC(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    int maxi = 0;
    vector<vector<int>> tmp_a(m);
    for(int c=0;c<m;c++)
    {
        unordered_map<int,int> map1;
        for(int i=0;i<n;i++)
        {
            if(a[i][c]==0) continue;
            map1[a[i][c]]++;
        }
        vector<pair<int,int>> temp;
        temp.assign(map1.begin(),map1.end());
        sort(temp.begin(),temp.end(),cmp);
        for(int i=0;i<temp.size();i++)
        {
            tmp_a[c].push_back(temp[i].first);
            tmp_a[c].push_back(temp[i].second);
            if(i==49) break;
        }
        if(maxi<tmp_a[c].size()) maxi = tmp_a[c].size();
    }
    for(int c=0;c<m;c++)
    {
        int cnt = maxi - tmp_a[c].size();
        for(int i=0;i<cnt;i++) tmp_a[c].push_back(0);
    }
    vector<vector<int>> tmp_a2(tmp_a[0].size(),vector<int>(tmp_a.size(),0));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<maxi;j++)
        {
            tmp_a2[j][i] = tmp_a[i][j];
        }
    }
    a.resize(tmp_a2.size(),vector<int>(tmp_a2[0].size(),0));
    a = tmp_a2;
}
int main()
{
    int r,c,k;
    cin >> r >> c >> k;
    r-=1;c-=1;
    vector<vector<int>> a(3,vector<int>(3,0));
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin >> a[i][j];
        }
    }
    int time = 0;
    while(true)
    {
        if(r>=0&&r<a.size()&&c>=0&&c<a[0].size())
        {
            if(a[r][c]==k) break;
        }
        int n = a.size();
        int m = a[0].size();
        if(n>=m) funcR(a);
        else funcC(a);
        time++;
        if(time==101)
        {
            time = -1;
            break;
        }
    }
    cout << time << '\n';
    return 0;
}
/*
    fucC를 진행할때 열을 기준으로 정렬을 진행하면 행의 길이가 뒤죽박죽이라 vector를 설정하는게
    난감함. 그래서 열을 기준으로 진행하는데 그걸 행마다 넣고 마지막에 a의 x,y를 바꿔주는 작업이
    필요함. 이 x,y를 바꿔주는 부분에서 오래걸림.
    굳이 이렇게 어렵게 vector를 매번 생성해주지말고 map[100][100]을 생성해놓고 매번 초기화해서
    풀면 훨씬 쉬웠을듯.
*/