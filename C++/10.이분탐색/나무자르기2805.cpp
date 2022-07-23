/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,m;
    cin >> n >> m;
    vector<long long> a;
    for(int i=0;i<n;i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);
    }
    long long start = 0;
    long long end = *max_element(a.begin(),a.end());
    long long mid;
    long long answer = -1;
    while(start<=end)
    {
        mid = (start+end)/2;
        long long sum = 0;
        for(int i=0;i<n;i++)
        {
            long long k = a[i] - mid;
            sum += max(0LL,k);
        }
        if(sum>=m)
        {
            if(answer<mid) answer = mid;
            start = mid+1;
        }
        else if(sum<m) end = mid-1;
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<long long> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     long long start = 0;
//     long long end = *max_element(a.begin(),a.end());
//     long long maxi = 0;
//     while(start<=end)
//     {
//         long long mid = (start+end)/2;
//         long long sum = 0;
//         for(int i=0;i<n;i++)
//         {
//             long long cut = a[i] - mid;
//             sum += max(0LL,cut);
//         }
//         if(sum>=m)
//         {
//             if(maxi<mid) maxi = mid;
//             start = mid + 1;
//         }
//         else end = mid - 1;
//     }
//     cout << maxi << '\n'; 
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(int argc, char const *argv[])
{
  long long n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  long long start = 0;
  long long end = *max_element(a.begin(),a.end());
  long long maxi = -1;
  while(start<=end) {
    long long mid = (start+end)/2;
    long long sum = 0;
    for(int i=0;i<n;i++) {
      long long temp = a[i]-mid;
      sum += max(0LL,temp);
    }
    if(sum>=m) {
      maxi = max(maxi,mid);
      start = mid+1;
    }
    else end = mid-1;
  }

  cout << maxi << '\n';
  return 0;
}
// 이분탐색은 답이 여러개일때, 등호를 초과에 넣느냐, 미만에 넣느냐에 따라 도달하는 위치가 달라짐.
// 여러 답 중 최대값을 원하면 올라가도록 등호를 넣어줘야 최대값에 도달함.






















