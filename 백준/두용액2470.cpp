#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int mini = -1;
    int min_first = 0;
    int min_second = 0;
    int start = 0;
    int end = n-1;
    while(start<end)
    {
        int sum = a[start] + a[end];
        if(mini==-1||mini>abs(sum))
        {
            mini = abs(sum);
            min_first = start;
            min_second = end;
        }
        if(sum>0) end--;
        else if(sum<0) start++;
        else break;
    }
    cout << a[min_first] << ' ' << a[min_second] << '\n';
    return 0;
}