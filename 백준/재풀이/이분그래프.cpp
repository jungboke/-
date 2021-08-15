#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
vector<int> a[20001];
bool check[20001];
int color[20001];
void dfs(int num)
{
    check[num] = true;
    for(int k : a[num])
    {
        if(check[k] == false)
        {
            color[k] = 3 - color[num];
            dfs(k);
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=1;i<=n;i++) a[i].clear();
        memset(color,0,sizeof(color));
        memset(check,false,sizeof(check));
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(check[i]==false)
            {
                color[i] = 1;
                dfs(i);
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int temp = color[i];
            for(int k : a[i])
            {
                if(temp==color[k])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
        if(flag == true) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
