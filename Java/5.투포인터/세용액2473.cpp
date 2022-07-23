/*
    두용액문제의 상위버전. int형들을 다 더해서 long long으로 만들수 없고 따로 long long으로
    형변환뒤 덧셈을 해줘야함.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <cmath>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end());
//     long long min = -1;
//     int min1 = 0;
//     int min2 = 0;
//     int min3 = 0;
//     for(int i=0;i<a.size()-2;i++)
//     {
//         int start = i+1;
//         int end = a.size()-1;
//         while(start<end)
//         {
//             long long sum = (long long)a[i]+(long long)a[start]+(long long)a[end];
//             if(min==-1||min>abs(sum))
//             {
//                 min = abs(sum);
//                 min1 = i;
//                 min2 = start;
//                 min3 = end;
//             }
//             if(sum>0) end--;
//             else if(sum<0) start++;
//             else if(sum==0)
//             {
//                 cout << a[i] << ' ' << a[start] << ' ' << a[end] << '\n';
//                 return 0;
//             }
//         }
//     }
//     cout << a[min1] << ' ' << a[min2] << ' ' << a[min3] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  long long mini = -1;
  int ans[3] = {0};
  for(int i=0;i<n-2;i++) {
    int x = a[i];
    int start = i+1;
    int end = n-1;
    while(start<end) {
      long long sum = (long long)x+a[start]+a[end];
      if(mini==-1||abs(sum)<mini) {
        mini = abs(sum);
        ans[0] = x;
        ans[1] = a[start];
        ans[2] = a[end];
      }
      if(a[start]+a[end]<-x) {
        start+=1;
      } else if(a[start]+a[end]>-x) {
        end-=1;
      } else {
        cout << x << ' ' << a[start] << ' ' << a[end] << '\n';
        return 0;
      }
    }
  }
  cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';
  return 0;
}