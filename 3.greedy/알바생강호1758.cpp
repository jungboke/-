#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    long long answer = 0;
    for(int i=0;i<n;i++)
    {
        int num = a[i] - i;
        if(num>=0) answer += num;
    }
    cout << answer << '\n';
    return 0;
}