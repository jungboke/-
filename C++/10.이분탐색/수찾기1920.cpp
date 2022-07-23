#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  int m;
  cin >> m;
  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    int start = 0;
    int end = n-1;
    bool flag = false;
    while(start<=end) {
      int mid = (start+end)/2;
      if(a[mid]>x) end = mid-1;
      else if(a[mid]<x) start = mid+1;
      else {
        flag = true;
        break;
      }
    }
    if(flag==true) cout << 1 << '\n';
    else cout << 0 << '\n';
  }
  return 0;
}
