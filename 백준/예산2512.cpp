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
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int start = 0;
    int end = *max_element(a.begin(),a.end());
    int maxi = 0;
    while(start<=end)
    {
        int mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]<=mid)
            {
                sum += a[i];
            }
            else if(a[i]>mid)
            {
                sum += mid;
            }
        }
        if(sum>m)
        {
            end = mid-1;
        }
        else if(sum<=m)
        {
            start = mid+1;
            if(maxi<mid) maxi = mid;
        }
    }
    cout << maxi << '\n';
    return 0;
}
/*
    이분탐색은 lowerbound, upperbound개념으로 생각해보기.
*/