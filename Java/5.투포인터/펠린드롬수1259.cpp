#include <bits/stdc++.h>
using namespace std;

bool Prime_Check(int x) {
  if(x==0||x==1) return false;
  if(x==2) return true;
  for(int i=2;i<=sqrt(x);i++) {
    if(x%i==0) return false;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int answer = 0;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    if(Prime_Check(x)) answer+=1;
  }
  cout << answer << '\n';
  return 0;
}

