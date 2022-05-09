// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int n,k;
//     cin >> n >> k;
//     vector<vector<int>> a(n,vector<int>(k,0));
//     vector<int> ck;
//     vector<int> result;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<k;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for(int i=0;i<k;i++)
//     {
//         ck.push_back(i);
//     }
//     vector<int> perm;
//     for(int i=0;i<3;i++) perm.push_back(1);
//     for(int i=0;i<k-3;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     do
//     {
//         vector<int> temp;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1) temp.push_back(ck[i]); 
//         }
//         int sum = 0;
//         for(int i=0;i<n;i++)
//         {
//             int maxi = 0;
//             for(int j=0;j<temp.size();j++)
//             {
//                 if(maxi<a[i][temp[j]]) maxi = a[i][temp[j]];
//             }
//             sum += maxi;
//         }
//         result.push_back(sum);
//     }while(next_permutation(perm.begin(),perm.end()));
//     cout << *max_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a[31];
bool check[31];
int answer = 0;
int N,M;

int cal(vector<int> temp) {
  int sum = 0;
  for(int i=0;i<N;i++) {
    int maxi = -1;
    for(int j=0;j<temp.size();j++) {
      maxi = max(maxi,a[i][temp[j]-1]);
    }
    sum += maxi;
  }

  return sum;
}

void dfs(vector<int> temp) {
  if(temp.size()==3) {
    answer = max(answer,cal(temp));
    return;
  }
  for(int i=1;i<=M;i++) {
    if(check[i]==true) continue;
    temp.push_back(i);
    check[i] = true;
    dfs(temp);
    check[i] = false;
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;M=m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }
  vector<int> temp;
  dfs(temp);
  
  cout << answer << '\n';
  return 0;
}