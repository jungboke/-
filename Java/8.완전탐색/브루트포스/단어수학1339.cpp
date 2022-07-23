/*
  map을 사용하여 문제를 해결할 때는 map의 search과정에서
  발생하는 시간복잡도도 생각해야함.
*/
#include <bits/stdc++.h>
using namespace std;
set<char> s;
vector<int> a;
vector<string> words;
int alp[30];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int i=0;i<temp.size();i++) {
      s.insert(temp[i]);
    }
    words.push_back(temp);
  }
  for(int i=0;i<s.size();i++) {
    a.push_back(9-i);
  }
  sort(a.begin(),a.end());
  vector<char> vec_s;
  vec_s.assign(s.begin(),s.end());
  int maxi = -1;
  do {
    for(int i=0;i<vec_s.size();i++) {
      alp[vec_s[i]-'A'] = a[i];
    }
    int sum = 0;
    for(int i=0;i<words.size();i++) {
      int temp = 0;
      for(int j=0;j<words[i].size();j++) {
        temp = temp*10 + alp[words[i][j]-'A'];
      }
      sum+=temp;
    }
    maxi = max(maxi,sum);
  } while(next_permutation(a.begin(),a.end()));
  cout << maxi << '\n';
  return 0;
}