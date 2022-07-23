/*
  점화식을 세울줄 알아야 하는 문제.
*/
#include <bits/stdc++.h>
using namespace std;

long long find(long long k) {
  if(k==1) return 0;
  long long i;
  for(i=1;i*2<k;i*=2);
  return !find(k-i);
}

int main(long long argc, char const *argv[])
{
  long long k;
  cin >> k;
  cout << find(k) << '\n';
  return 0;
}
