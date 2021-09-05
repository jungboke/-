#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int mini = n+1;
    int start = 0;
    int end = 0;
    long long sum = a[0];
    while(start<=end&&end<n)
    {
        if(sum>=s)
        {
            if(mini>end-start+1) mini = end-start+1;
            sum-=a[start];
            start++;
        }
        else
        {
            end++;
            sum+=a[end];
        }
    }
    if(mini==n+1) cout << 0 << '\n';
    else cout << mini << '\n';
    return 0;
}