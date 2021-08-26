#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long start = 1;
    long long end = n;
    long long ans = 0;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long x = (mid*(mid+1)) / 2;
        if(x>n) end = mid-1;
        else if(x<=n)
        {
            ans = mid;
            start = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}