#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        cout << *min_element(a.begin(),a.end()) << ' ' << *max_element(a.begin(),a.end()) << '\n';
    }
    return 0;
}