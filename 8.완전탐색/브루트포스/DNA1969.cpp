#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        a[i] = temp;
    }
    string result = "";
    int cnt = 0;
    for(int i=0;i<m;i++)
    {
        map<char,int> map1;
        for(int j=0;j<n;j++)
        {
            map1[a[j][i]]++;
        }
        int maxi = 0;
        char alp;
        for(auto k : map1)
        {
            if(k.second>maxi)
            {
                maxi = k.second;
                alp = k.first;
            }
        }
        result += alp;
        cnt += (n-maxi);
    }
    cout << result << '\n';
    cout << cnt << '\n';
    return 0;
}