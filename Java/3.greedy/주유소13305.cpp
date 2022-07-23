/*
    코드 최적화하기.
*/
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
    vector<long long> dist(n-1);
    for(int i=0;i<n-1;i++)
    {
        cin >> dist[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    long long answer = 0LL;
    int start = 0;
    while(start<n-1)
    {
        int x = start;
        start++;
        while(start<n-1)
        {
            if(a[x]>a[start]) break;
            start++;
        }
        long long dsum = 0;
        for(int i=x;i<start;i++)
        {
            dsum += dist[i];
        }
        answer += dsum * a[x];
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
//     vector<long long> a(n-1);
//     vector<long long> b(n);
//     for(int i=0;i<n-1;i++)
//     {
//         cin >> a[i];
//     }
//     for(int i=0;i<n;i++)
//     {
//         cin >> b[i];
//     }
//     long long mini = -1;
//     long long sum = 0;
//     for(int i=0;i<n-1;i++)
//     {
//         if(mini==-1||mini>b[i]) mini = b[i];
//         sum += mini*a[i];
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
  vector<long> dist(n-1);
  vector<long> target(n);
  for(int i=0;i<n-1;i++) {
    cin >> dist[i];
  }
  for(int i=0;i<n;i++) {
    cin >> target[i];
  }
  long answer = 0;
  long now = target[0];
  for(int i=0;i<n-1;i++) {
    if(target[i]<now) now = target[i]; 
    answer += (now*dist[i]);
  }

  cout << answer << '\n';

  return 0; 
}