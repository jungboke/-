#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long start = 0;
    long long end = sqrt(n);
    long long mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        long long x = pow(mid,2);
        if(x>=n||x<=0)
        {
            end = mid-1;
        }
        else if(x<n)
        {
            start = mid+1;
        }
    }
    if(mid*mid > n) mid--;
    else if(mid*mid < n) mid++;
    cout << mid << '\n';
    return 0;
}
/*

*/