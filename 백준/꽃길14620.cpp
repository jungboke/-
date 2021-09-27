#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {0,-1,0,1,0};
int dy[] = {0,0,1,0,-1};
int check(vector<pair<int,int>> a,vector<vector<int>> ary_a)
{
    int n = ary_a.size();
    vector<vector<int>> board(n,vector<int>(n,0));
    int sum = 0;
    for(int i=0;i<a.size();i++)
    {
        int x,y;
        x = a[i].first;
        y = a[i].second;
        for(int i=0;i<5;i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<n&&board[nx][ny]!=1)
            {
                board[nx][ny] = 1;
                sum += ary_a[nx][ny];
            }
            else return -1;
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    vector<pair<int,int>> b;
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            b.push_back(make_pair(i,j));
        }
    }
    vector<int> perm;
    for(int i=0;i<3;i++) perm.push_back(1);
    for(int i=0;i<n*n-3;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<pair<int,int>> temp;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) temp.push_back(b[i]);
        }
        int k = check(temp,a);
        if(k!=-1) result.push_back(k);
    }while(next_permutation(perm.begin(),perm.end()));
    cout << *min_element(result.begin(),result.end()) << '\n';
    return 0;
}
/*
    next_permutation으로 완전탐색해서 풀었는데 ,dfs로도 문제해결 가능할듯.
*/