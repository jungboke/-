#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    double answer = a[n-1];
    for(int i=0;i<n-1;i++)
    {
        answer += (a[i]/2);
    }
    cout << answer << '\n';
    return 0;
}