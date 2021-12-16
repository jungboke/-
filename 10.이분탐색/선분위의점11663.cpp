/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        int sidx = lower_bound(a.begin(),a.end(),x) - a.begin();
        int eidx = upper_bound(a.begin(),a.end(),y) - a.begin();
        cout << eidx-sidx << '\n';
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        auto it = lower_bound(a.begin(),a.end(),x);
        auto it2 = upper_bound(a.begin(),a.end(),y);
        cout << it2-it << '\n';
    }
    return 0;
}