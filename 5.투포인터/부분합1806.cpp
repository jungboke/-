/*
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
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = 0;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        end = i;
        sum += a[i];
        if(sum>=k) break;
    }
    if(sum<k)
    {
        cout << 0 << '\n';
        return 0;
    }
    int mini = end-start+1;
    while(start<=end&&end<n)
    {
        sum -= a[start];
        start++;
        while(end<n)
        {
            if(sum>=k)
            {
                if(mini>end-start+1) mini = end-start+1;
                break;
            }
            end++;
            sum += a[end];
        }
    }
    cout << mini << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    int start = 0;
    int end = 0;
    int mini = -1;
    for(int i=0;i<n;i++)
    {
        if(sum+a[i]>=m)
        {
            sum += a[i];
            end = i;
            break;
        }
        else sum += a[i];
    }
    if(sum<m)
    {
        cout << 0 << '\n';
        return 0;
    }
    mini = end-start+1;
    while(end<n)
    {
        sum -= a[start];
        start++;
        while(end<n)
        {
            if(sum>=m) break;
            end++;
            sum += a[end];
        }
        if(mini>end-start+1) mini = end-start+1;
    }
    cout << mini << '\n';
    return 0;
}





















