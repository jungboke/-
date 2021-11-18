#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_map<string,int> map1;
    unordered_map<int,string> map2;
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        string x;
        cin >> x;
        map1[x] = i;
        map2[i] = x;
    }
    for(int i=0;i<m;i++)
    {
        string x;
        cin >> x;
        if(atoi(x.c_str())==0)
        {
            cout << map1[x] << '\n';
        }
        else
        {
            cout << map2[stoi(x)] << '\n';
        }
    }
    return 0;
}