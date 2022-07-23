#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int> a, vector<int> temp, int start) {
  if(temp.size()==6) {
    for(int i=0;i<temp.size();i++) {
      cout << temp[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=start;i<a.size();i++) {
    temp.push_back(a[i]);
    dfs(a,temp,i+1);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  while(true) {
    int n;
    cin >> n;
    if(n==0) break;
    vector<int> a;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(),a.end());
    vector<int> temp;
    dfs(a,temp,0);
    cout << '\n';
  }
  return 0;
}