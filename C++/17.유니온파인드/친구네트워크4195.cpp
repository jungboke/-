/*
  기존의 분리집합 방식과는 다르게 매번 그룹의 사이즈를
  구해줘야함. 원래는 그룹의 사이즈를 구할 때, 전체에서
  같은 부모를 가진 노드들의 개수의 합으로 구했는데, 배열의
  크기가 너무 커서 이 방법이 안됨. 따라서 group으로 그룹의
  사이즈를 매번 갱신함.
*/

#include <bits/stdc++.h>
using namespace std;
int parent[200001];
int group[200001];
unordered_map<string,int> map1;

int Find(int x) {
  if(parent[x]==x) return x;
  else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  if(x==y) return;
  parent[y] = x;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--) {
    for(int i=0;i<200001;i++) {
      parent[i] = i;
      group[i] = 1;
    }
    int n;
    cin >> n;
    int idx = 1;
    for(int i=0;i<n;i++) {
      string x[2];
      for(int j=0;j<2;j++) {
        cin >> x[j];
        if(map1[x[j]]==0) map1[x[j]] = idx++;
      }
      if(Find(map1[x[0]])!=Find(map1[x[1]])) {
        group[Find(map1[x[0]])] += group[Find(map1[x[1]])];
      }
      Union(map1[x[0]],map1[x[1]]);
      cout << group[Find(map1[x[0]])] << '\n';
    }
  }
  return 0;
}