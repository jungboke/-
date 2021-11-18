#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    long long start = 1;
    long long end = *max_element(a.begin(),a.end()) * m;
    long long mini = end+1;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long man = 0;
        for(int i=0;i<a.size();i++)
        {
            man += mid/a[i];
        }
        if(man>=m)
        {
            end = mid-1;
            if(mini>mid) mini = mid;
        }
        else
        {
            start = mid+1;
        }
    }
    cout << mini << '\n';
    return 0;
}
/*
    이분탐색시 upperbound,lowerbound 개념으로 생각.
*/