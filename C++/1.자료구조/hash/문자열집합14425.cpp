#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  cin >> n >> m;
  unordered_map<string,int> map1;
  int answer = 0;
  for(int i=0;i<n;i++) {
    string a;
    cin >> a;
    map1[a]++;
  }
  for(int i=0;i<m;i++) {
    string a;
    cin >> a;
    if(map1[a]!=0) answer++; 
  }
  cout << answer << '\n';
  return 0;
}