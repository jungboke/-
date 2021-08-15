#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[1001];
bool check[1001];
void go(int num)
{
    check[num] = true;
    for(int k : a[num])
    {
        if(check[k]==false)
        {
            go(k);
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(check[i]==false)
        {
            cnt++;
            go(i);
        }
    }
    cout << cnt << '\n';
    return 0;
}