// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int a[51][51];
// vector<int> result;
// int main()
// {
//     int n,k;
//     cin >> n >> k;
//     vector<pair<int,int>> ch;
//     vector<pair<int,int>> nh;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//             if(a[i][j]==2)
//             {
//                 ch.push_back(make_pair(i,j));
//             }
//             else if(a[i][j]==1)
//             {
//                 nh.push_back(make_pair(i,j));
//             }
//         }
//     }
//     vector<int> perm;
//     for(int i=0;i<k;i++) perm.push_back(1);
//     for(int i=0;i<ch.size()-k;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     do
//     {
//         vector<pair<int,int>> temp;
//         int sum = 0;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1) temp.push_back(ch[i]);
//         }
//         for(int i=0;i<nh.size();i++)
//         {
//             int sx = nh[i].first;
//             int sy = nh[i].second;
//             int mini = 99999999;
//             for(int j=0;j<temp.size();j++)
//             {
//                 int ex = temp[j].first;
//                 int ey = temp[j].second;
//                 if(abs(sx-ex)+abs(sy-ey)<mini) mini = abs(sx-ex) + abs(sy-ey);
//             }
//             sum += mini;
//         }
//         result.push_back(sum);

//     }while(next_permutation(perm.begin(),perm.end()));
//     cout << *min_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int a[51][51];
vector<pair<int,int>> ho;
vector<pair<int,int>> ch;
int mini = INF;

void cal(vector<pair<int,int>> temp) {
  int sum = 0;
  for(int i=0;i<ho.size();i++) {
    int sx,sy;
    tie(sx,sy) = ho[i];
    int min_sum = INF;
    for(int j=0;j<temp.size();j++) {
      int ex,ey;
      tie(ex,ey) = temp[j];
      int dist = abs(ex-sx) + abs(ey-sy);
      min_sum = min(min_sum,dist);
    }
    sum += min_sum;
  }
  mini = min(mini,sum);
}

void dfs(vector<pair<int,int>> temp, int start, int m) {
  if(temp.size()==m) {
    cal(temp);
    return;
  }
  for(int i=start;i<ch.size();i++) {
    temp.push_back(ch[i]);
    dfs(temp,i+1,m);
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
      if(a[i][j]==1) ho.push_back(make_pair(i,j));
      if(a[i][j]==2) ch.push_back(make_pair(i,j));
    }
  }
  vector<pair<int,int>> temp;
  dfs(temp,0,m);
  cout << mini << '\n'; 
  return 0;
}
