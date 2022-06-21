/*
  시간복잡도를 해결하기 위해 크루스칼을 사용하고,
  그리디적인 해결방법을 알아야 함.
*/

#include <bits/stdc++.h>
using namespace std;
int parent[100001];
struct Edge {
  int from;
  int to;
  int cost;
  Edge(int from, int to, int cost) : from(from), to(to), cost(cost) {}
  bool operator < (const Edge &other) const {
    return cost < other.cost;
  }
};

int Find(int x) {
  if(x==parent[x]) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x==y) return;
  parent[y] = x;
}

vector<pair<int,int>> X;
vector<pair<int,int>> Y;
vector<pair<int,int>> Z;
vector<Edge> E;
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    X.push_back(make_pair(x,i));
    Y.push_back(make_pair(y,i));
    Z.push_back(make_pair(z,i));
  }
  sort(X.begin(),X.end());
  sort(Y.begin(),Y.end());
  sort(Z.begin(),Z.end());
  for(int i=0;i<n-1;i++) {
    E.push_back(Edge(X[i].second,X[i+1].second,abs(X[i+1].first-X[i].first)));
    E.push_back(Edge(Y[i].second,Y[i+1].second,abs(Y[i+1].first-Y[i].first)));
    E.push_back(Edge(Z[i].second,Z[i+1].second,abs(Z[i+1].first-Z[i].first)));
  }
  sort(E.begin(),E.end());
  for(int i=1;i<=n;i++) {
    parent[i] = i; 
  }
  long long answer = 0;
  for(int i=0;i<E.size();i++) {
    auto e = E[i];
    int x = Find(e.to);
    int y = Find(e.from);
    if(x!=y) {
      Union(e.to,e.from);
      answer += e.cost;
    }
  }
  cout << answer << '\n';
  return 0;
}
