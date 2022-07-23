#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    queue<int> q;
    vector<int> answer;
    for(int i=1;i<=n;i++) {
      q.push(i);
    }
    int cnt = 1;
    while(!q.empty()) {
      int x = q.front();
      q.pop();
      if(cnt==m) {
        answer.push_back(x);
        cnt = 0;
      }
      else q.push(x);
      cnt++;
    }
    cout << '<';
    for(int i=0;i<answer.size();i++) {
      cout << answer[i];
      if(i!=answer.size()-1) cout << ", ";
    }
    cout << '>';
    return 0;
}