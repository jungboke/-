/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string,int> map1;
    vector<string> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n;i++)
    {
        int idx = a[i].find(".")+1;
        string temp = a[i].substr(idx,a[i].size()-idx);
        map1[temp]++;
    }
    for(auto k : map1)
    {
        cout << k.first << ' ' << k.second << '\n';
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     map<string,int> map1;
//     for(int i=0;i<n;i++)
//     {
//         string a;
//         cin >> a;
//         string temp = "";
//         int idx = a.find('.');
//         int length = a.size() - idx;
//         temp = a.substr(idx+1,length);
//         map1[temp]++;
//     }
//     for(auto k : map1)
//     {
//         cout << k.first << ' ' << k.second << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<string> a;
map<string,int> map1;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    string x;
    cin >> x;
    a.push_back(x);
  }
  for(int i=0;i<n;i++) {
    int idx = a[i].find('.');
    string temp = a[i].substr(idx+1);
    map1[temp]+=1;
  }
  for(auto k:map1) {
    cout << k.first << ' ' << k.second << '\n';
  }
  return 0;
}
