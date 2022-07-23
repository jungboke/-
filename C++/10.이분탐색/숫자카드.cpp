#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int N;

bool exist_check(int x) {
  int start = 0;
  int end = N;
  while(start<=end) {
    int mid = (start+end)/2;
    if(a[mid]>x) end = mid-1;
    else if(a[mid]<x) start = mid+1;
    else return true;
  }

  return false;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  N=n;
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
    cout << exist_check(x) << ' ';
  }
  return 0;
}