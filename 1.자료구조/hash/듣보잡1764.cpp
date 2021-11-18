#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    map<string,int> map1;
    vector<string> result;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        map1[x]++;
    }
    for(int i=0;i<m;i++)
    {
        string x;
        cin >> x;
        if(map1[x]!=0) result.push_back(x);
    }
    sort(result.begin(),result.end());
    cout << result.size() << '\n';
    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}