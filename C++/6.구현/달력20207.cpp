/*
    광고삽입 문제처럼 배열을 사용해 누적시켜야 하며, 달력의 끝에서 강제적으로 컷팅당하는 것도 생각해야함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int check[366];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        for(int i=a;i<=b;i++)
        {
            check[i]++;
        }
    }
    int answer = 0;
    int maxi = 0;
    int cnt = 0;
    for(int i=1;i<=365;i++)
    {
        if(check[i]==0)
        {
            answer += cnt*maxi;
            maxi = 0;
            cnt = 0;
            continue;
        }
        if(maxi<check[i]) maxi = check[i];
        cnt++;
    }
    answer += cnt * maxi;
    cout << answer << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int a[1001];
// int main()
// {
//     int n;
//     cin >> n;
//     int m = 0;
//     for(int i=0;i<n;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         for(int j=x;j<=y;j++)
//         {
//             a[j]++;
//         }
//         if(m<y) m = y;
//     }
//     int answer = 0;
//     int maxi = 0;
//     int cnt = 0;
//     for(int i=1;i<=m;i++)
//     {
//         if(maxi<a[i]) maxi = a[i];
//         if(a[i]==0)
//         {
//             answer += maxi*cnt;
//             maxi = 0;
//             cnt = 0;
//         }
//         else cnt++;
//     }
//     answer += maxi*cnt;
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[400];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    for(int j=x;j<=y;j++) {
      a[j]+=1;
    }
  }
  int answer = 0;
  int maxi = 0;
  int cnt = 0;
  for(int i=1;i<=365;i++) {
    if(a[i]==0) {
      answer += maxi*cnt;
      maxi = 0;
      cnt = 0;
    } else {
      maxi = max(maxi,a[i]);
      cnt+=1;
    }
  }
  answer += maxi*cnt;
  cout << answer << '\n';
  return 0;
}
