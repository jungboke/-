#include <bits/stdc++.h>
#define ll long long
using namespace std;
int prime[4000001];
vector<int> a;
// 소수 : 0, 아님 : 1
int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  prime[1] = 1;
  for(int i=2;i<=n;i++) {
    if(prime[i]==0) {
      a.push_back(i);
      for(int j=i+i;j<=n;j+=i) {
        prime[j] = 1;
      }
    }
  }
  int answer = 0;
  int start = 0;
  int end = 0;
  int sum = 0;
  for(int i=0;i<a.size();i++) {
    if(sum+a[i]>n) {
      break;
    }
    else {
      sum+=a[i];
      end = i;
      if(sum==n) answer+=1; 
    }
  }
  while(start<=end&&end<a.size()) {
    sum-=a[start++];
    end++;
    while(end<a.size()) {
      if(sum+a[end]<=n) {
        sum+=a[end];
        if(sum==n) answer+=1;
        end++;
      } else {
        end--;
        break;
      }
    }
  }
  cout << answer << '\n';
  return 0;
}