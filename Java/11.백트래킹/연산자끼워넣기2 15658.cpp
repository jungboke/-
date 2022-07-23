#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
vector<int> num;
int maxi = -INF;
int mini = INF;

void dfs(int idx, int now, int target, int plus, int minus, int mul, int div) {
  if(idx==target) {
    maxi = max(maxi,now);
    mini = min(mini,now);
    return;
  }
  if(plus>0) dfs(idx+1,now+num[idx+1],target,plus-1,minus,mul,div);
  if(minus>0) dfs(idx+1,now-num[idx+1],target,plus,minus-1,mul,div);
  if(mul>0) dfs(idx+1,now*num[idx+1],target,plus,minus,mul-1,div);
  if(div>0) dfs(idx+1,now/num[idx+1],target,plus,minus,mul,div-1);
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    num.push_back(x);
  }
  int op[4];
  for(int i=0;i<4;i++) {
    cin >> op[i];
  }
  dfs(0,num[0],n-1,op[0],op[1],op[2],op[3]);
  cout << maxi << '\n';
  cout << mini << '\n';
  return 0;
}