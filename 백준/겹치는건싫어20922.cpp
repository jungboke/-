#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    map<int,int> map1;
    int start = 0;
    int end = 0;
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(map1[a[i]]+1>m) break;
        else
        {
            map1[a[i]]++;
            end = i;
        }
    }
    maxi = end-start+1;
    while(end<n)
    {
        map1[a[start]]--;
        start++;
        end++;
        while(end<n)
        {
            if(map1[a[end]]+1<=m)
            {
                map1[a[end]]++;
                if(end-start+1>maxi) maxi = end-start+1;
                end++;
            }
            else
            {
                end--;
                break;
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}
// 보석쇼핑의 다른 버전.