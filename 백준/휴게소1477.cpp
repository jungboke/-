#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m,l;
    cin >> n >> m >> l;
    vector<int> a(n);
    vector<int> dist;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    a.push_back(0);
    a.push_back(l);
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++)
    {
        int x = a[i+1] - a[i];
        dist.push_back(x);
    }
    int start = 1;
    int end = *max_element(dist.begin(),dist.end());
    int mini = end;
    while(start<=end)
    {
        int mid = (start+end) / 2;
        int sum = 0;
        for(int i=0;i<dist.size();i++)
        {
            sum += (dist[i]-1)/mid;
        }
        if(sum<=m)
        {
            if(mini>mid) mini = mid;
            end = mid-1;
        }
        else if(sum>m)
        {
            start = mid+1;
        }
    }
    cout << mini << '\n';
    return 0;
}