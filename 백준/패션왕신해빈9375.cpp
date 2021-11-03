#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        unordered_map<string,int> map1;
        for(int i=0;i<n;i++)
        {
            string x,y;
            cin >> x >> y;
            map1[y]++;
        }
        int sum = 1;
        for(auto k:map1)
        {
            sum *= (k.second+1);
        }
        cout << sum-1 << '\n';
    }
    return 0;
}