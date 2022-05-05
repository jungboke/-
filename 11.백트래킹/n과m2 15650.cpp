/*
  오름차순 배열에서 dfs진행시, 오름차순 정답을 얻고 싶은경우 start변수를 적용.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool check[10];
// void dfs(vector<int> a,vector<int> temp,int cnt,int start)
// {
//     if(temp.size()==cnt)
//     {
//         for(int i=0;i<temp.size();i++)
//         {
//             cout << temp[i] << ' ';
//         }
//         cout << '\n';
//         return;
//     }
//     for(int i=start;i<a.size();i++)
//     {
//         if(check[i]==false)
//         {
//             check[i] = true;
//             temp.push_back(a[i]);
//             dfs(a,temp,cnt,i+1);
//             temp.pop_back();
//             check[i] = false;
//         }
//     }
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<int> a;
//     for(int i=1;i<=n;i++)
//     {
//         a.push_back(i);
//     }
//     vector<int> temp;
//     dfs(a,temp,m,0);
//     return 0;
// }
#include <bits/stdc++.h>
#define max _max
using namespace std;
vector<int> a;
bool check[10];

bool up_check(vector<int> temp) {
  vector<int> temp2 = temp;
  sort(temp2.begin(),temp2.end());
  if(temp2==temp) return true;
  else return false;
} 

void dfs(vector<int> temp,int max) {
  if(temp.size()==max) {
    if(up_check(temp)==true) {
      for(int i=0;i<temp.size();i++) {
        cout << temp[i] << ' ';
      }
      cout << '\n';
    }
    return;
  }
  for(int i=0;i<a.size();i++) {
    if(check[i]==true) continue;
    temp.push_back(a[i]);
    check[i] = true;
    dfs(temp,max);
    check[i] = false;
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) {
    a.push_back(i);
  }
  vector<int> temp;
  dfs(temp,m);

  return 0;
}