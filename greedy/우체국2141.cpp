#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<long long,long long>> a;
    for(int i=0;i<n;i++)
    {
        long long x,y;
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    vector<long long> dist(n);
    long long sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += a[i].second;
        dist[i] = sum;
    }
    int start = 0;
    int end = a.size()-1;
    long long mini = -1;
    while(start<=end)
    {
        int mid = (start+end)/2;
        long long left = dist[mid];
        long long right = dist[dist.size()-1] - dist[mid];
        if(left>=right)
        {
            end = mid-1;
            if(mini==-1||mini>a[mid].first) mini = a[mid].first;
        }
        else if(left<right)
        {
            start = mid+1;
        }
    }
    cout << mini << '\n';
    return 0;
}
/*
    우체국을 어느 마을이던 설정해도 거기서 나머지 마을들의 거리의 합은 비슷하게 됨.
    결국은 인구수의 분배가 중요한데, 인구수의 합의 중간지점에 설정해야 가장 최소가될듯함.
*/