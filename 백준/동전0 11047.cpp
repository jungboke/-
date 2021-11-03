#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    int answer = 0;
    for(int i=0;i<a.size();i++)
    {
        if(m/a[i]==0) continue;
        else
        {
            answer += m/a[i];
            m = m%a[i];
        }
    }
    cout << answer << '\n';
    return 0;
}