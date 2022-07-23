// 1 4 3 을 가져왔다면 1 4, 4 3 처럼 ind[]배열 생성하기
// 위상 정렬
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[1001];
int ind[1001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        int x;
        cin >> x;
        for(int j=0;j<x;j++)
        {
            int y;
            cin >> y;
            temp.push_back(y);
        }
        for(int j=1;j<temp.size();j++)
        {
            int x = temp[j-1];
            int y = temp[j];
            a[x].push_back(y);
            ind[y]++;
        }
    }
    vector<int> result;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0) q.push(i); 
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        result.push_back(x);
        for(auto k:a[x])
        {
            ind[k]--;
            if(ind[k]==0)
            {
                q.push(k);
            }
        }
    }
    if(result.size()!=n) cout << 0 << '\n';
    else
    {
        for(int i=0;i<result.size();i++)
        {
            cout << result[i] << '\n';
        }
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int ind[1001];
// vector<int> a[1001];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x;
//         cin >> x;
//         vector<int> temp(x);
//         for(int j=0;j<x;j++)
//         {
//             cin >> temp[j];
//         }
//         for(int j=1;j<x;j++)
//         {
//             a[temp[j-1]].push_back(temp[j]);
//             ind[temp[j]]++;
//         }
//     }
//     queue<int> q;
//     vector<int> answer;
//     for(int i=1;i<=n;i++)
//     {
//         if(ind[i]==0)
//         {
//             q.push(i);
//             answer.push_back(i);
//         } 
//     }
//     while(!q.empty())
//     {
//         int x = q.front();
//         q.pop();
//         for(auto k:a[x])
//         {
//             ind[k]--;
//             if(ind[k]==0)
//             {
//                 q.push(k);
//                 answer.push_back(k);
//             }
//         }
//     }
//     if(answer.size()!=n) cout << 0 << '\n';
//     else
//     {
//         for(int i=0;i<answer.size();i++)
//         {
//             cout << answer[i] << '\n';
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[1001];
int ind[1001];

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    vector<int> temp;
    for(int j=0;j<x;j++) {
      int y;
      cin >> y;
      temp.push_back(y);
    }
    for(int j=1;j<temp.size();j++) {
      int y = temp[j];
      int x = temp[j-1];
      a[x].push_back(y);
      ind[y]+=1;
    }
  }
  queue<int> q;
  for(int i=1;i<=n;i++) {
    if(ind[i]==0) {
      q.push(i);
    }
  }
  vector<int> answer;
  while(!q.empty()) {
    int x = q.front();
    q.pop();
    answer.push_back(x);
    for(auto k:a[x]) {
      ind[k]-=1;
      if(ind[k]==0) {
        q.push(k);
      }
    }
  }
  if(answer.size()!=n) cout << 0 << '\n';
  else {
    for(int i=0;i<answer.size();i++) {
      cout << answer[i] << '\n';
    }
  }
  return 0;
}
