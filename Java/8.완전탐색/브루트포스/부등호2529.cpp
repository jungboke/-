#include <bits/stdc++.h>
using namespace std;
vector<char> a;
vector<string> result;
bool check[10];

bool ans_check(vector<int> temp) {
  for(int i=0;i<a.size();i++) {
    if(a[i]=='<') {
      if(temp[i]>temp[i+1]) return false;
    } else {
      if(temp[i]<temp[i+1]) return false;
    }
  }
  return true;
}

void dfs(vector<int> temp, int cnt) {
  if(temp.size()==cnt) {
    if(ans_check(temp)) {
      string x = "";
      for(int i=0;i<temp.size();i++) {
        x+=to_string(temp[i]);
      }
      result.push_back(x);
    }
    return;
  }
  for(int i=0;i<=9;i++) {
    if(check[i]==true) continue;
    check[i] = true;
    temp.push_back(i);
    dfs(temp,cnt);
    temp.pop_back();
    check[i] = false;
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    char x;
    cin >> x;
    a.push_back(x);
  }
  vector<int> temp;
  dfs(temp,n+1);
  cout << *max_element(result.begin(),result.end()) << '\n';
  cout << *min_element(result.begin(),result.end()) << '\n';
  return 0;
}