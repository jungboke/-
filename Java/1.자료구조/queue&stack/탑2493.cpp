/*
    배열에서 각 인덱스마다 이전 인덱스까지의 값들의 데이터가 필요하면 stack을 사용하여 문제해결함. 이렇게 안하면
    전의 인덱스들마다 하나씩 참조하여 값을 알아내야 해서 시간이 오래걸림.
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     stack<pair<int,int>> st;
//     for(int i=0;i<n;i++)
//     {
//         int x;
//         cin >> x;
//         while(!st.empty())
//         {
//             if(x>st.top().first) st.pop();
//             else break;
//         }
//         if(st.empty())
//         {
//             st.push(make_pair(x,i+1));
//             cout << 0 << ' ';
//         }
//         else
//         {
//             cout << st.top().second << ' ';
//             st.push(make_pair(x,i+1));
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  stack<pair<int,int>> st;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    while(!st.empty()&&st.top().first<x) st.pop();
    if(st.empty()) cout << 0 << ' ';
    else cout << st.top().second + 1 << ' ';
    st.push(make_pair(x,i));
  }
  return 0;
}
