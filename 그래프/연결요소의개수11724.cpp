#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<vector<int>> a(1001);
bool check[1001];
void dfs(int num)
{
    check[num] = true;
    for(int i=0;i<a[num].size();i++)
    {
        int next = a[num][i];
        if(check[next] == false)
        dfs(next);
    }
}

int main(){

    int n,m; // n 정점 m 간선
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int count = 0;
    for(int i=1;i<=n;i++)
    {
        if(check[i] == false)
        {
            count++;
            dfs(i);
        }
    }
    cout << count << '\n';
    return 0;
}