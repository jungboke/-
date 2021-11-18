/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin >> n >> m;
    vector<long long> a;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    long long start = 0;
    long long end = *max_element(a.begin(),a.end());
    long long mid;
    long long answer = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long k = a[i] - mid;
            sum += max(0LL,k);
        }
        if(sum>=m)
        {
            if(answer<mid) answer = mid;
            start = mid+1;
        }
        else if(sum<m) end = mid-1;
    }
    cout << answer << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    long long start = 0;
    long long end = *max_element(a.begin(),a.end());
    long long maxi = 0;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long cut = a[i] - mid;
            sum += max(0LL,cut);
        }
        if(sum>=m)
        {
            if(maxi<mid) maxi = mid;
            start = mid + 1;
        }
        else end = mid - 1;
    }
    cout << maxi << '\n'; 
    return 0;
}






















