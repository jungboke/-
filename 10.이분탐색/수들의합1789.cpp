/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long start = 1;
    long long end = n;
    long long ans = 0;
    while(start<=end)
    {
        long long mid = (start+end)/2;
        long long x = (mid*(mid+1)) / 2;
        if(x>n) end = mid-1;
        else if(x<=n)
        {
            ans = mid;
            start = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     long long n;
//     cin >> n;
//     long long start = 1;
//     long long end = n;
//     long long maxi = 0;
//     while(start<=end)
//     {
//         long long mid = (start+end)/2;
//         long long sum = mid*(mid+1)/2;
//         if(sum<=n)
//         {
//             if(maxi<mid) maxi = mid;
//             start = mid+1;
//         }
//         else end = mid-1;
//     }
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  long long s;
  cin >> s;
  long long start = 1;
  long long end = s;
  long long maxi = 0;
  while(start<=end) {
    long long mid = (start+end)/2;
    long long sum = ((mid+1)*mid)/2;
    if(sum<=s) {
      maxi = max(maxi,mid);
      start = mid+1;
    }
    else if(sum>s) end = mid-1;
    
  }
  cout << maxi << '\n';
  return 0;
}























