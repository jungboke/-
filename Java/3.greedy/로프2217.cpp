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
    int cnt = 0;
    int maxi = -1;
    for(int i=0;i<n;i++)
    {
        cnt++;
        if(a[i]*cnt>maxi) maxi = a[i]*cnt;
    }
    cout << maxi << '\n';
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     sort(a.begin(),a.end(),greater<>());
//     int sum = 0;
//     int maxi = 0;
//     for(int i=0;i<n;i++)
//     {
//         int temp = a[i] * (i+1);
//         if(maxi<temp) maxi = temp;
//     }
//     cout << maxi << '\n';
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
  int maxi = 0;
  for(int i=0;i<n;i++) {
    int temp = a[i]*(i+1);
    if(maxi<temp) maxi = temp;
  }

  cout << maxi << '\n';

  return 0; 
}
