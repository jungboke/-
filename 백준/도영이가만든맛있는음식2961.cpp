#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> result;
void dfs(vector<pair<long long,long long>> a,int idx,int s,int b,int cnt)
{
    if(idx==a.size())
    {
        if(cnt!=0) result.push_back(abs(s-b));
        return;
    }
    dfs(a,idx+1,s*a[idx].first,b+a[idx].second,cnt+1);
    dfs(a,idx+1,s,b,cnt);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<long long,long long>> a(n);
    for(int i=0;i<n;i++)
    {
        long long x,y;
        cin >> x >> y;
        a[i] = make_pair(x,y);
    }
    dfs(a,0,1,0,0);
    cout << *min_element(result.begin(),result.end()) << '\n';
    return 0;
}
/*
    일반적인 비트마스크 혹은 재귀문제.
*/