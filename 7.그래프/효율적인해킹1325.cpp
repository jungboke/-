// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <string.h>
// using namespace std;
// vector<int> a[10001];
// bool check[10001];
// void dfs(int num)
// {
//     check[num] = true;
//     for(auto k:a[num])
//     {
//         if(check[k]==false) dfs(k);
//     }
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a[y].push_back(x);
//     }
//     vector<pair<int,int>> result;
//     int maxi = -1;
//     for(int i=1;i<=n;i++)
//     {
//         memset(check,false,sizeof(check));
//         dfs(i);
//         int answer = 0;
//         for(int i=1;i<=n;i++)
//         {
//            if(check[i]==true) answer++;
//         }
//         if(maxi<answer) maxi = answer;
//         result.push_back(make_pair(i,answer));
//     }
//     sort(result.begin(),result.end());
//     for(int i=0;i<result.size();i++)
//     {
//         if(result[i].second==maxi)
//             cout << result[i].first << ' ';
//     }
//     cout << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[10001];
bool check[10001];

void dfs(int x) {
  check[x] = true;
  for(auto k:a[x]) {
    if(check[k]==false) {
      dfs(k);
    }
  }
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    a[y].push_back(x);
  }
  vector<pair<int,int>> answer;
  for(int i=1;i<=n;i++) {
    dfs(i);
    int cnt = 0;
    for(int i=1;i<=n;i++) {
      if(check[i]==true) {
        cnt++;
      }
    }
    answer.push_back(make_pair(cnt,i));
    memset(check,false,sizeof(check));
  }
  sort(answer.begin(),answer.end());
  int maxi = -1;
  for(int i=0;i<answer.size();i++) {
    maxi = max(maxi,answer[i].first);
  }
  for(int i=0;i<answer.size();i++) {
    if(answer[i].first==maxi) {
      cout << answer[i].second << ' ';
    }
  }  

  return 0;
}

