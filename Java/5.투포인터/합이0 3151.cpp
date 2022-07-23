/*
  두용액 문제와 비슷한데, a[mid]+a[end]==0 이 되는 경우를 잘 커버해야함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)    
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long answer = 0;
    for(int i=0;i<n-2;i++)
    {
        int start = i;
        int mid = i+1;
        int end = n-1;
        int j=n;
        while(mid<end)
        {
            int sum = a[mid] + a[end];
            if(sum+a[start]>0) end--;
            else if(sum+a[start]<0) mid++;
            else if(sum+a[start]==0)
            {
                if(a[mid]==a[end])
                {
                    answer += end-mid;
                }
                else
                {
                    auto k1 = lower_bound(a.begin(),a.end(),a[end]);
                    auto k2 = upper_bound(a.begin(),a.end(),a[end]);
                    answer += k2-k1;
                }
                mid++;
            }
        }
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
//     long long cnt = 0;
//     for(int i=0;i<n-2;i++)
//     {
//         int start = i;
//         int mid = i+1;
//         int end = n-1;
//         while(mid<end)
//         {
//             int sum = a[mid] + a[end];
//             if(sum+a[start]>0) end--;
//             else if(sum+a[start]<0) mid++;
//             else if(sum+a[start]==0)
//             {
//                 if(a[mid]==a[end])
//                 {
//                     cnt += end-mid; 
//                 }
//                 else
//                 {
//                     auto idx1 = lower_bound(a.begin(),a.end(),a[end]);
//                     auto idx2 = upper_bound(a.begin(),a.end(),a[end]);
//                     cnt += idx2-idx1;
//                 }
//                 mid++;
//             }
//         }
//     }
//     cout << cnt << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
long long answer = 0;

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
  for(int i=0;i<n-2;i++) {
    int x = a[i];
    int start = i+1;
    int end = n-1;
    while(start<end) {
      int sum = a[start]+a[end];
      if(sum+x>0) end-=1;
      else if(sum+x<0) start+=1;
      else if(sum+x==0) {
        if(a[start]==a[end]) {
          int temp = end-start+1;
          answer += (temp*(temp-1))/2;
          break;
        }
        int prev_start = start;
        int prev_end = end;
        while(a[start]==a[prev_start]) start+=1;
        while(a[end]==a[prev_end]) end-=1;
        answer += (start-prev_start)*(prev_end-end);
      }
    }
  }

  cout << answer << '\n';
  return 0;
}
