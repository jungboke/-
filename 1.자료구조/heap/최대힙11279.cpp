// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     priority_queue<int> pq;
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin >> x;
//         if(x==0)
//         {
//             if(pq.empty()) cout << 0 << '\n';
//             else
//             {
//                 int temp = pq.top();
//                 pq.pop();
//                 cout << temp << '\n';
//             }
//         }
//         else pq.push(x);
//     }
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
  priority_queue<int> pq;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    if(x!=0) {
      pq.push(x);
    } else {
      if(pq.empty()) cout << 0 << '\n';
      else {
        cout << pq.top() << '\n';
        pq.pop();
      }
    }
  }
  return 0;
}