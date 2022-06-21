#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int to;
  double cost;
  Edge(int to, double cost) : to(to), cost(cost) {}
};
struct cmp {
  bool operator()(Edge a, Edge b) {
    return (a.cost>b.cost);
  }
};
vector<Edge> a[101];
bool check[101];

double cal(pair<double,double> a, pair<double,double> b) {
  return sqrt(pow(b.first-a.first,2) + pow(b.second-a.second,2));
}

int main(int argc, char const *argv[])
{
  cout.setf(ios::fixed);
  cout.precision(2);
  int n;
  cin >> n;
  vector<pair<double,double>> star;
  for(int i=0;i<n;i++) {
    double x,y;
    cin >> x >> y;
    star.push_back(make_pair(x,y));
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      if(i==j) continue;
      a[i].push_back(Edge(j,cal(star[i],star[j])));
    }
  }
  priority_queue<Edge,vector<Edge>,cmp> pq;
  check[0] = true;
  for(auto k:a[0]) {
    pq.push(k);
  }
  double answer = 0;
  while(!pq.empty()) {
    auto e = pq.top();
    pq.pop();
    int x = e.to;
    if(check[x]==true) continue;
    check[x] = true;
    answer += e.cost;
    for(auto k:a[x]) {
      pq.push(k);
    }
  }
  cout << answer << '\n';
  return 0;
}