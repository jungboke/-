#include <vector>
#include <algorithm>
#include <iostream>
#define INF 10000000
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    int mini = INF;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        mini = min(mini,a[i]);
    }
    int sum = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        sum += max(0,a[i]-mini);
        if(a[i]>mini) cnt++;
    }
    cout << sum << ' ' << cnt << '\n';
    return 0;
}