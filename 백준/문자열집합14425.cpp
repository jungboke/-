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
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        map1[x]++;
    }
    int answer = 0;
    for(int i=0;i<m;i++)
    {
        string x;
        cin >> x;
        if(map1[x]==1) answer++;
    }
    cout << answer << '\n';
    return 0;
}