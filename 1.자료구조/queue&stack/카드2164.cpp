// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <queue>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     queue<int> q;
//     for(int i=1;i<=n;i++)
//         q.push(i);
//     while(q.size()>1)
//     {
//         q.pop();
//         int x = q.front();
//         q.pop();
//         q.push(x);
//     }
//     cout << q.front() << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<int> dq;
    for(int i=1;i<=n;i++) {
      dq.push_back(i);
    }
    while(dq.size()!=1) {
      dq.pop_front();
      int x = dq.front();
      dq.pop_front();
      dq.push_back(x);
    }
    cout << dq.front() << '\n';
    return 0;
}