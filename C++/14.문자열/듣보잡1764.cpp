// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     map<string,int> map1;
//     vector<string> result;
//     for(int i=0;i<n;i++)
//     {
//         string x;
//         cin >> x;
//         map1[x]++;
//     }
//     for(int i=0;i<m;i++)
//     {
//         string x;
//         cin >> x;
//         if(map1[x]!=0) result.push_back(x);
//     }
//     sort(result.begin(),result.end());
//     cout << result.size() << '\n';
//     for(int i=0;i<result.size();i++)
//     {
//         cout << result[i] << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> map1;

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    string x;
    cin >> x;
    map1[x]+=1;
  }
  vector<string> answer;
  for(int i=0;i<m;i++) {
    string x;
    cin >> x;
    map1[x]+=1;
    if(map1[x]==2) {
      answer.push_back(x);
    }
  }
  sort(answer.begin(),answer.end());
  cout << answer.size() << '\n';
  for(int i=0;i<answer.size();i++) {
    cout << answer[i] << '\n';
  }
  return 0;
}
