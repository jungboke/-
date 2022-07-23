#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> result;

int cal(vector<int> temp) {
  int sum = a[0];
  for(int i=0;i<temp.size();i++) {
    if(temp[i]==0) sum += a[i+1];
    else if(temp[i]==1) sum -= a[i+1];
    else if(temp[i]==2) sum *= a[i+1];
    else sum /= a[i+1];
  }
  return sum;
}

bool temp_check(vector<int> temp) {
  bool flag = true;
  int num[4] = {0};
  for(int i=0;i<temp.size();i++) {
    if(temp[i]==0) num[0]+=1;
    else if(temp[i]==1) num[1]+=1;
    else if(temp[i]==2) num[2]+=1;
    else num[3]+=1;
  }
  for(int i=0;i<b.size();i++) {
    if(b[i]!=num[i]) flag = false;
  }
  return flag;
}

void dfs(vector<int> temp, int m) {
  if(temp.size()==m) {
    if(temp_check(temp)) result.push_back(cal(temp));
    return;
  }
  for(int i=0;i<4;i++) {
    temp.push_back(i);
    dfs(temp,m);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  for(int i=0;i<4;i++) {
    int x;
    cin >> x;
    b.push_back(x);
  }
  vector<int> temp;
  dfs(temp,n-1);
  cout << *max_element(result.begin(),result.end()) << '\n';
  cout << *min_element(result.begin(),result.end()) << '\n';
  return 0;
}