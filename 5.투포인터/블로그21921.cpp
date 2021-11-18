/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int maxsum = 0;
    for(int i=0;i<m;i++)
    {
        maxsum += a[i];
    }
    int sum = maxsum;
    result.push_back(sum);
    for(int i=m;i<n;i++)
    {
        sum = sum + a[i] - a[i-m];
        result.push_back(sum);
    }
    maxsum = *max_element(result.begin(),result.end());
    if(maxsum==0)
    {
        cout << "SAD" << '\n';
        return 0;
    }
    int cnt = 0;
    for(int i=0;i<result.size();i++)
    {
        if(result[i]==maxsum) cnt++;
    }
    cout << maxsum << '\n';
    cout << cnt << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int sum = 0;
    for(int i=0;i<m;i++)
    {
        sum+=a[i];
    }
    result.push_back(sum);
    for(int i=m;i<n;i++)
    {
        sum = sum + a[i] - a[i-m];
        result.push_back(sum);
    }
    int maxsum = *max_element(result.begin(),result.end()); 
    if(maxsum==0) cout << "SAD" << '\n';
    else
    {
        int cnt = 0;
        for(int i=0;i<result.size();i++)
        {
            if(result[i]==maxsum) cnt++;
        }
        cout << maxsum << '\n';
        cout << cnt << '\n';
    }
    return 0;
}






















