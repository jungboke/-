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
    int cnt = 0;
    int maxi = -1;
    for(int i=0;i<n;i++)
    {
        cnt++;
        if(a[i]*cnt>maxi) maxi = a[i]*cnt;
    }
    cout << maxi << '\n';
}