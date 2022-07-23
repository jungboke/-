#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Edge
{
    int to;
    int cost;
    Edge(int to,int cost) : to(to),cost(cost) {}
};
bool check[1001];
vector<Edge> a[1001];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
        }
        cout << n-1 << '\n';
    }
    return 0;
}
/*
    문제 조건 내 연결 그래프라는 조건은 모든 정점이 연결되어 있다는 뜻이고, 최소 간선을
    통해 모든 정점을 방문하라는 말은 MST라는 뜻. MST의 간선의 개수는 정점수-1 임.
*/