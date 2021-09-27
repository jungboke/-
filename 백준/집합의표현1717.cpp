#include <iostream>
#include <algorithm>
#define rank _rank
using namespace std;
int parent[1000001];
int rank[1000001];
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
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) {
        rank[x] = rank[y] + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<=n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    while (m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 0) {
            Union(x, y);
        } else {
            x = Find(x);
            y = Find(y);
            if (x == y) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}