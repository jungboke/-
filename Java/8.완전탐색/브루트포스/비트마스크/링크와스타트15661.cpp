// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int cal(vector<vector<int>> a,vector<int> start,vector<int> link)
// {
//     int startsum = 0;
//     int linksum = 0;
//     for(int i=0;i<start.size();i++)
//     {
//         for(int j=0;j<start.size();j++)
//         {
//             startsum += a[start[i]][start[j]];
//         }
//     }
//     for(int i=0;i<link.size();i++)
//     {
//         for(int j=0;j<link.size();j++)
//         {
//             linksum += a[link[i]][link[j]];
//         }
//     }
//     return abs(startsum-linksum);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> a(n,vector<int>(n,0));
//     vector<int> result;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for(int i=1;i<(1<<n)-1;i++)
//     {
//         vector<int> start;
//         vector<int> link;
//         for(int j=0;j<n;j++)
//         {
//             if((i&(1<<j))!=0)
//             {
//                 start.push_back(j);
//             }
//             else link.push_back(j);
//         }
//         result.push_back(cal(a,start,link));
//     }
//     cout << *min_element(result.begin(),result.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[21][21];
vector<int> result;

int cal(vector<int> vec) {
  int sum = 0;
  for(int i=0;i<vec.size();i++) {
    for(int j=0;j<vec.size();j++) {
      sum += a[vec[i]][vec[j]];
    }
  }
  return sum;
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  for(int i=1;i<(1<<n)-1;i++) {
    vector<int> first;
    vector<int> second;
    for(int j=0;j<n;j++) {
      if(i&(1<<j)) first.push_back(j);
      else second.push_back(j);
    }
    int first_sum = cal(first);
    int second_sum = cal(second);
    result.push_back(abs(first_sum-second_sum));
  }
  cout << *min_element(result.begin(),result.end()) << '\n';
  return 0;
}