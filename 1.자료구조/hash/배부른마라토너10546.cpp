#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string,int> map1;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        map1[x]++;
    }
    for(int i=0;i<n-1;i++)
    {
        string x;
        cin >> x;
        map1[x]--;
    }
    for(auto k:map1)
    {
        cout << k.second << '\n';
    }
    return 0;
}
/*
    map1[string]++를 하고 다시 --를 해서 0이되도 map1에 남아있음.
*/