#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string,int> map1;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        map1[x]++;
    }
    int maxi = 0;
    for(auto k:map1)
    {
        int count = k.second;
        if(maxi<count) maxi = count;
    }
    for(auto k:map1)
    {
        if(k.second==maxi)
        {
            cout << k.first << '\n';
            break;
        }
    }
    return 0;
}