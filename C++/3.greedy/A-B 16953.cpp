/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int change(long long m,long long n)
{
    int cnt = 0;
    while(m!=0)
    {
        if(m%10==1)
        {
            m = m/10;
        }
        else if(m%2==1) return -1;
        else if(m%2==0)
        {
            m = m/2;
        }
        cnt++;
        if(m==n) break;
    }
    if(m!=n) return -1;
    else return cnt;
}
int main()
{
    long long n,m;
    cin >> n >> m;
    if(change(m,n)==-1) cout << -1 << '\n';
    else cout << change(m,n)+1 << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     int answer = 1;
//     while(true)
//     {
//         if(n==m) break;
//         else if(m<n)
//         {
//             answer = -1;
//             break;
//         }
//         if(m%10==1)
//         {
//             m = m/10;
//             answer++;
//         }
//         else if(m%2==0)
//         {
//             m = m/2;
//             answer++;
//         }
//         else
//         {
//             answer = -1;
//             break;
//         }
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  int cnt = 1;
  while(m!=n) {
    if((m%2==1&&m%10!=1)||m<n) {
      cnt = -1;
      break;
    }
    if(m%2==0) {
      m/=2;
      cnt+=1;
    } else {
      m/=10;
      cnt+=1;
    }
  }
  cout << cnt << '\n';
  return 0;
}