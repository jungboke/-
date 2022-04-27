/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end(),greater<>());
    int answer = 0;
    for(int i=0;i<a.size();i++)
    {
        if((i+1)%3==0) continue;
        answer += a[i];
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
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
//     sort(a.begin(),a.end(),greater<>());
//     long long sum = 0;
//     for(int i=0;i<n;i++)
//     {
//         if((i+1)%3==0) continue;
//         sum += a[i];
//     }
//     cout << sum << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end(),greater<>());
  long long sum = 0;
  for(int i=0;i<n;i++) {
    if(i%3==2) continue;
    sum += a[i];
  }

  cout << sum << '\n';
  return 0; 
}