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
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int mini = -1;
    int min_first = 0;
    int min_second = 0;
    int start = 0;
    int end = n-1;
    while(start<end)
    {
        int sum = a[start] + a[end];
        if(mini==-1||mini>abs(sum))
        {
            mini = abs(sum);
            min_first = start;
            min_second = end;
        }
        if(sum>0) end--;
        else if(sum<0) start++;
        else break;
    }
    cout << a[min_first] << ' ' << a[min_second] << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     int start = 0;
//     int end = n-1;
//     int mini = -1;
//     int a_start = 0;
//     int a_end = 0;
//     while(start<end)
//     {
//         long long sum = a[start] + a[end];
//         if(mini==-1||mini>abs(sum))
//         {
//             mini = abs(sum);
//             a_start = start;
//             a_end = end;
//         }
//         if(sum<0) start++;
//         else if(sum>0) end--;
//         else if(sum==0) break;
//     }
//     cout << a[a_start] << ' ' << a[a_end] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  int begin = 0;
  int end = n-1;
  int mini = -1;
  int ans_begin;
  int ans_end;
  while(begin<end) {
    int sum = a[begin]+a[end];
    if(mini==-1||mini>abs(sum)) {
      mini = abs(sum);
      ans_begin = begin;
      ans_end = end;
    }
    if(sum<0) {
      begin++;
    } else if(sum>0) {
      end--;
    } else if(sum==0) {
      break;
    }
  }
  
  cout << a[ans_begin] << ' ' << a[ans_end] << '\n';
  return 0; 
}
/*
    이분탐색보다는 투포인터가 더 맞는 문제같음.
*/




















