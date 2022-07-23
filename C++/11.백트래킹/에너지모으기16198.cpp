#include <bits/stdc++.h>
using namespace std;
int maxi = -1;
int N;

void dfs(vector<int> a, int now) {
  if(a.size()==2) {
    maxi = max(maxi,now);
    return;
  }
  for(int i=0;i<a.size();i++) {
    if(i==0||i==a.size()-1) continue;
    int sum = a[i-1]*a[i+1];
    vector<int> temp = a;
    temp.erase(temp.begin()+i);
    dfs(temp,now+sum);

  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  vector<int> a;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  dfs(a,0);
  cout << maxi << '\n';
  return 0;
}