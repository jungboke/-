#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
void dfs(vector<int> a,vector<int> temp,int cnt)
{
    if(temp.size()==cnt)
    {
        for(int i=0;i<temp.size();i++)
        {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }
    int last = -1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=last)
        {
            last = a[i];
            temp.push_back(a[i]);
            dfs(a,temp,cnt);
            temp.pop_back();
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<int> temp;
    dfs(a,temp,m);
    return 0;
}