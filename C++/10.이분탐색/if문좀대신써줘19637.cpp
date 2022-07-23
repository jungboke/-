/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<pair<string,int>> name;
    vector<int> a(m);
    vector<int> b(m);
    unordered_map<int,string> map1;
    for(int i=0;i<n;i++)
    {
        string a;
        int b;
        cin >> a >> b;
        name.push_back(make_pair(a,b));
    }
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    b = a;
    sort(b.begin(),b.end());
    int start = 0;
    for(int i=0;i<name.size();i++)
    {
        int x = name[i].second;
        string y = name[i].first;
        int idx = upper_bound(b.begin(),b.end(),x) - b.begin();
        for(int j=start;j<idx;j++)
        {
            map1[b[j]] = y;
        }
        start = idx;
    }
    for(int i=0;i<a.size();i++)
    {
        cout << map1[a[i]] << '\n';
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
//     int n,m;
//     cin >> n >> m;
//     vector<string> a(n);
//     vector<int> b(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//         cin >> b[i];
//     }
//     for(int i=0;i<m;i++)
//     {
//         int x;
//         cin >> x;
//         auto it = lower_bound(b.begin(),b.end(),x);
//         cout << a[it-b.begin()] << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<string> a;
vector<int> b;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<n;i++) {
    string x;
    int y;
    cin >> x >> y;
    a.push_back(x);
    b.push_back(y);
  }
  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    int idx = lower_bound(b.begin(),b.end(),x) - b.begin();
    cout << a[idx] << '\n';
  }
  return 0;
}
