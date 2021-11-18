#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
vector<pair<int,int>> a[10001];
bool check[10001];
int maxi = 0;
vector<int> leaf;
void dfs2(int num)
{
    check[num] = true;
    bool flag = false;
    for(auto k:a[num])
    {
        if(check[k.first]==false)
        {
            flag = true;
            dfs2(k.first);
        }
        if(flag==false)
        {
            leaf.push_back(num);
        }
    }
}
void dfs(int num,int sum)
{
    check[num] = true;
    bool flag = false;
    for(auto k:a[num])
    {
        if(check[k.first]==false)
        {
            flag = true;
            dfs(k.first,sum+k.second);
        }
    }
    if(flag==false)
    {
        if(maxi<sum) maxi = sum;
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int x,y,m;
        cin >> x >> y >> m;
        a[x].push_back(make_pair(y,m));
        a[y].push_back(make_pair(x,m));
    }
    dfs2(1);
    for(int i=0;i<leaf.size();i++)
    {
        memset(check,false,sizeof(check));
        dfs(leaf[i],0);
    }
    cout << maxi << '\n';
    return 0;
}
// 더 최적의 방법이 있음, 메모리 초과발생시 vector의 크기도 살펴보기.