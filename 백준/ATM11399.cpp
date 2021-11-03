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
    sort(a.begin(),a.end());
    int answer = 0;
    int sum = 0;
    for(int i=0;i<a.size();i++)
    {
        sum += a[i];
        answer += sum;
    }
    cout << answer << '\n';
    return 0;
}