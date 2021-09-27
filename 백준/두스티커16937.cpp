#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void custom_swap(pair<int,int> &a)
{
    int temp = a.first;
    a.first = a.second;
    a.second = temp;
}
bool check(pair<int,int> a,pair<int,int> b,int n,int m)
{
    // 초기
    if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
    else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

    custom_swap(a);
    if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
    else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

    custom_swap(b);
    if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
    else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

    custom_swap(a);
    if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
    else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

    return false;
}
int main()
{
    int n,m,k;
    cin >> n >> m;
    cin >> k;
    vector<pair<int,int>> a;
    vector<int> result;
    for(int i=0;i<k;i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    if(a.size()==1)
    {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> perm;
    for(int i=0;i<2;i++) perm.push_back(1);
    for(int i=0;i<k-2;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<pair<int,int>> temp;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) temp.push_back(a[i]);
        }
        if(check(temp[0],temp[1],n,m)==true)
        {
            int sum = temp[0].first*temp[0].second + temp[1].first*temp[1].second;
            result.push_back(sum);
        }
    }while(next_permutation(perm.begin(),perm.end()));
    if(result.size()==0) cout << 0 << '\n';
    else cout << *max_element(result.begin(),result.end()) << '\n';   
    return 0;
}
/*
    애초에 스티커가 1개주어질 경우제외해야함. 스티커를 붙이는 경우의수 줄이기.
*/