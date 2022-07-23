/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a;
    vector<int> perm;
    set<string> s; 
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<k;i++) perm.push_back(1);
    for(int i=0;i<n-k;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<int> vec;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) vec.push_back(a[i]);
        }
        sort(vec.begin(),vec.end());
        do
        {
            string temp = "";
            for(int i=0;i<vec.size();i++)
            {
                temp+=to_string(vec[i]);
            }
            s.insert(temp);
        } while (next_permutation(vec.begin(),vec.end()));
        
    } while (next_permutation(perm.begin(),perm.end()));
    cout << s.size() << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
//     int n,k;
//     cin >> n >> k;
//     vector<int> a(n);
//     vector<int> perm;
//     set<string> s;
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     for(int i=0;i<k;i++) perm.push_back(1);
//     for(int i=0;i<n-k;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     do
//     {
//         vector<int> result;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1) result.push_back(a[i]);
//         }
//         sort(result.begin(),result.end());
//         do
//         {
//             string temp = "";
//             for(int i=0;i<result.size();i++)
//             {
//                 temp += to_string(result[i]);
//             }
//             s.insert(temp);
//         }while(next_permutation(result.begin(),result.end()));
        
//     }while(next_permutation(perm.begin(),perm.end()));
    
//     cout << s.size() << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
set<string> s;

int main(int argc, char const *argv[])
{
  int n,k;
  cin >> n >> k;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  sort(a.begin(),a.end());
  vector<int> perm;
  for(int i=0;i<n-k;i++) perm.push_back(0);
  for(int i=0;i<k;i++) perm.push_back(1);
  sort(perm.begin(),perm.end());
  do {
    vector<int> temp;
    for(int i=0;i<perm.size();i++) {
      if(perm[i]==1) temp.push_back(a[i]);
    }
    sort(temp.begin(),temp.end());
    do {
      string num = "";
      for(int i=0;i<temp.size();i++) {
        num += to_string(temp[i]);
      }
      s.insert(num);
    } while(next_permutation(temp.begin(),temp.end()));
  } while(next_permutation(perm.begin(),perm.end()));
  
  cout << s.size() << '\n';
  return 0;
}