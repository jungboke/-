#include <bits/stdc++.h>
using namespace std;
vector<string> arr;

bool cmp(string a, string b) {
  if(a.size()==b.size()) return (a<b);
  return (a.size()<b.size());
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  set<string> s;
  for(int i=0;i<n;i++) {
    string x;
    cin >> x;
    s.insert(x);
  }
  arr.assign(s.begin(),s.end());
  sort(arr.begin(),arr.end(),cmp);

  for(int i=0;i<arr.size();i++) {
    cout << arr[i] << '\n';
  }
  return 0;
}