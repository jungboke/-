/*
#include <iostream>
using namespace std;
int parent[101];
int Find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x != y) {
        parent[y] = x;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        parent[i] = i;
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        Union(x, y);
    }
    int ans = 0;
    for (int i=2; i<=n; i++) {
        if (Find(1) == Find(i)) {
            ans += 1;
        }
    }
    cout << ans << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#define rank _rank
using namespace std;
int parent[101];
int rank[101];
int Find(int x)
{
    if(x==parent[x])
    {
        return x;
    }
    else return parent[x] = Find(parent[x]);
}
void Union(int x,int y)
{
    x = Find(x);
    y = Find(y);
    if(x==y) return;
    if(rank[x]<rank[y]) swap(x,y);
    parent[y] = x;
    if(rank[x]==rank[y]) rank[x]+=1;
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) parent[i] = i;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        Union(x,y);
    }
    int answer = 0;
    for(int i=2;i<=n;i++)
    {
        if(Find(i)==Find(1)) answer++;
    }
    cout << answer << '\n';
    return 0;
}














