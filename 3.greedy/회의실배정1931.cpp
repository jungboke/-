#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second) return (a.first<b.first);
    return (a.second<b.second);
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end(),cmp);
    int answer = 0;
    int end = 0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i].first>=end)
        {
            answer+=1;
            end = a[i].second;
        }
    }
    cout << answer << '\n';
    return 0;
}