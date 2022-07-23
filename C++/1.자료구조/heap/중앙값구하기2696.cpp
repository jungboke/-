/*
    multiset을 이용한 쉬운 방법과 priority_queue를 2개 사용하여 mid보다 크고 작은 부분을 나타내는 더 어려운 방법
    두개가 있음.
    priority_queue 2개를 사용한 방법은 왼쪽이 무조건 오른쪽보다 1개 크도록 설정하고,
    왼쪽 끝값을 mid로 생각함. 그리고 값을 매번 왼쪽부터 넣어서 2개 이상 차이나면
    하나를 오른쪽으로 옮겨줌.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (n/2)+1 << '\n';
        multiset<int> ms;
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            ms.insert(x);
            if(i%2==1)
            {
                int idx = ms.size()/2;
                auto it = ms.begin();
                for(int j=0;j<idx;j++) it++;
                if(cnt==10)
                {
                    cout << '\n';
                    cnt = 0;
                }
                cout << *it << ' ';
                cnt++;
            }
        }
        cout << '\n';
    }
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (n/2)+1 << '\n';
        priority_queue<int> pq1; // 앞 우선순위 큐
        priority_queue<int,vector<int>,greater<>> pq2; // 뒤 우선순위큐
        int mid = 0;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            if(i==1)
            {
                mid = x;
                cout << mid << ' ';
                continue;
            }
            if(mid<x) pq2.push(x);
            else pq1.push(x);
            if(i%2==1)
            {
                if(pq1.size()<pq2.size())
                {
                    pq1.push(mid);
                    mid = pq2.top();
                    pq2.pop();
                }
                else if(pq1.size()>pq2.size())
                {
                    pq2.push(mid);
                    mid = pq1.top();
                    pq1.pop();
                }
                
                cout << mid << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         int mid = 0;
//         int cnt = 0;
//         priority_queue<int> pq1;
//         priority_queue<int,vector<int>,greater<>> pq2;
//         cout << (n+1)/2 << '\n';
//         for(int i=0;i<n;i++)
//         {
//             int x;
//             cin >> x;
//             if(i==0)
//             {
//                 mid = x;
//                 cout << mid << ' ';
//                 cnt++;
//                 continue;
//             }
//             if(x<=mid) pq1.push(x);
//             else pq2.push(x);

//             if((i+1)%2==1)
//             {
//                 if(pq2.size()>pq1.size())
//                 {
//                     int temp = mid;
//                     mid = pq2.top();
//                     pq2.pop();
//                     pq1.push(temp);
//                 }
//                 else if(pq2.size()<pq1.size())
//                 {
//                     int temp = mid;
//                     mid = pq1.top();
//                     pq1.pop();
//                     pq2.push(temp);
//                 }
//                 if(cnt==10)
//                 {
//                     cout << '\n';
//                     cnt = 0;
//                 }
//                 cout << mid << ' ';
//                 cnt++;
//             }
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<>> right;
    vector<int> result;
    int mid;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      left.push(x);
      if(!right.empty()) {
        if(left.top()>right.top()) {
          int right_temp = right.top();
          int left_temp = left.top();
          right.pop();
          left.pop();
          right.push(left_temp);
          left.push(right_temp);
        }
      }
      if(left.size()==right.size()+2) {
        right.push(left.top());
        left.pop();
      }
      mid = left.top();
      
      if(i%2==0) result.push_back(mid);
    }

    cout << result.size() << '\n';
    for(int i=0;i<result.size();i++) {
      cout << result[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}