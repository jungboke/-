/*
  분리집합에서 parent[x]는 항상 Find(x)가 아님. parent[x]의 값이
  다른 집합에 합쳐지면 parent[x]와 Find(x)가 달라짐.
*/
#include <bits/stdc++.h>
#define rank _rank
using namespace std;
int parent[1000001];
int rank[1000001];
int sum[1000001];

int Find(int x) {
  if(x==parent[x]) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x==y) return;
  if(rank[x]<rank[y]) swap(x,y);
  parent[y] = x;
  sum[x] += sum[y];
  if(rank[x]==rank[y]) rank[x]+=1;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=1;i<=1000000;i++) {
    parent[i] = i;
    sum[i] = 1;
  }
  for(int i=0;i<n;i++) {
    char x;
    cin >> x;
    if(x=='I') {
      int y,z;
      cin >> y >> z;
      Union(y,z);
    } else {
      int y;
      cin >> y;
      cout << sum[Find(y)] << '\n';
    }
  }
  return 0;
}
