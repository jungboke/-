#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int color[20001];
vector<vector<int>> a(20001);
void go(int num)
{
    for(int i=0;i<a[num].size();i++)
    {
        int next = a[num][i];
        if(color[next] != 0) continue;
        color[next] = 5 - color[num];
        go(next);
    }
}
int main(){

    int t;
    cin >> t;
    while(t--)
    {
        memset(color,0,sizeof(color));
        for(int i=0;i<a.size();i++)
        {
            a[i].clear();
        }
        int n,m; // n 정점 m 간선
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i] == 0)
            {
                color[i] = 2;
                go(i);
            }
        }
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            int temp = color[i];
            for(int j=0;j<a[i].size();j++)
            {
                int next = a[i][j];
                if(color[next] == temp)
                {
                    flag = false;
                }
            }
        }
        if(flag == true) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
// 일반배열은 memset, vector는 fill로 초기화, 모든 그래프가 연결되지 않고 연결요소로 이루어질수도 있음.
// string.h에 memset 존재.
