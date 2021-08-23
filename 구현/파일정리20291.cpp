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
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        int idx = a[i].find(".")+1;
        string temp = a[i].substr(idx,a[i].size()-idx);
        map1[temp]++;
    }
    for(auto k : map1)
    {
        cout << k.first << ' ' << k.second << '\n';
    }
    return 0;
}