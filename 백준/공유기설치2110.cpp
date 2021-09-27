#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check(long long mid,vector<long long> a,int cnt)
{
    long long start = a[0];
    cnt--;
    for(int i=1;i<a.size();i++)
    {
        if(a[i]-start>=mid)
        {
            cnt--;
            start = a[i];
            if(cnt==0) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long start = 1;
    long long end = a[n-1] - a[0];
    long long maxi = -1;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        if(check(mid,a,m)==true)
        {
            start = mid+1;
            if(maxi<mid) maxi = mid;
        }
        else
        {
            end = mid-1;
        }
    }
    cout << maxi << '\n';
    return 0;
}
/*
    무엇을 이분탐색기준으로 잡을것인가 잘생각하기.
*/