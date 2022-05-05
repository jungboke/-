/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<long long> answer;
    if(a.size()%2==1)
    {
        answer.push_back(a[a.size()-1]);
        a.erase(a.end()-1);
    }
    int start = 0;
    int end = a.size()-1;
    while(start<end)
    {
        answer.push_back(a[start]+a[end]);
        start++;
        end--;
    }
    cout << *max_element(answer.begin(),answer.end()) << '\n';
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
//     sort(a.begin(),a.end());
//     long long maxi = 0;
//     if(a.size()%2==1)
//     {
//         maxi = a[n-1];
//         a.erase(a.end()-1);
//     }
//     int start = 0;
//     int end = a.size()-1;
//     while(start<end)
//     {
//         long long sum = a[start]+a[end];
//         if(maxi<sum) maxi = sum;
//         start++;
//         end--; 
//     }
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<long long> a;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    long long x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  long long maxi;
  if(a.size()%2==0) maxi = -1;
  else {
    maxi = a[n-1];
    a.erase(a.end()-1);
  }
  for(int start=0, end=a.size()-1;start<end;start++, end--) {
    long long sum = a[start]+a[end];
    maxi = max(maxi,sum);
  }

  cout << maxi << '\n';
  return 0;
}