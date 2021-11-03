#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> diff;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<n;i++)
    {
        diff.push_back(a[i]-a[i-1]);
    }
    sort(diff.begin(),diff.end(),greater<>());
    int answer = 0;
    for(int i=m-1;i<diff.size();i++)
    {
        answer += diff[i];
    }
    cout << answer << '\n';
    return 0;
}