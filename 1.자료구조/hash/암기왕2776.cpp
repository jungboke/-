#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
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
        unordered_map<int,int> map1;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            map1[x]++;
        }
        int m;
        cin >> m;
        for(int i=0;i<m;i++)
        {
            int x;
            cin >> x;
            if(map1[x]!=0) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
    return 0;
}