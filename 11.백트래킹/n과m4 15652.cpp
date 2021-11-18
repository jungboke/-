#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void dfs(vector<int> a,vector<int> temp,int cnt,int start)
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
    for(int i=start;i<a.size();i++)
    {
        temp.push_back(a[i]);
        dfs(a,temp,cnt,i);
        temp.pop_back();
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        a.push_back(i);
    }
    vector<int> temp;
    dfs(a,temp,m,0);
    return 0;
}