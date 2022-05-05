/*
    애초에 스티커가 1개주어질 경우제외해야함. 스티커를 붙이는 경우의수 줄이기.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// void custom_swap(pair<int,int> &a)
// {
//     int temp = a.first;
//     a.first = a.second;
//     a.second = temp;
// }
// bool check(pair<int,int> a,pair<int,int> b,int n,int m)
// {
//     // 초기
//     if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
//     else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

//     custom_swap(a);
//     if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
//     else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

//     custom_swap(b);
//     if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
//     else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

//     custom_swap(a);
//     if(a.second+b.second<=m&&max(a.first,b.first)<=n) return true;
//     else if(a.first+b.first<=n&&max(a.second,b.second)<=m) return true;

//     return false;
// }
// int main()
// {
//     int n,m,k;
//     cin >> n >> m;
//     cin >> k;
//     vector<pair<int,int>> a;
//     vector<int> result;
//     for(int i=0;i<k;i++)
//     {
//         int x,y;
//         cin >> x >> y;
//         a.push_back(make_pair(x,y));
//     }
//     if(a.size()==1)
//     {
//         cout << 0 << '\n';
//         return 0;
//     }
//     vector<int> perm;
//     for(int i=0;i<2;i++) perm.push_back(1);
//     for(int i=0;i<k-2;i++) perm.push_back(0);
//     sort(perm.begin(),perm.end());
//     do
//     {
//         vector<pair<int,int>> temp;
//         for(int i=0;i<perm.size();i++)
//         {
//             if(perm[i]==1) temp.push_back(a[i]);
//         }
//         if(check(temp[0],temp[1],n,m)==true)
//         {
//             int sum = temp[0].first*temp[0].second + temp[1].first*temp[1].second;
//             result.push_back(sum);
//         }
//     }while(next_permutation(perm.begin(),perm.end()));
//     if(result.size()==0) cout << 0 << '\n';
//     else cout << *max_element(result.begin(),result.end()) << '\n';   
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
bool check[101];
int maxi = -1;
int H,W;

void cal(pair<int,int> a, pair<int,int> b) {
  bool flag = false;
  int x1,x2,y1,y2;
  tie(x1,y1) = a;
  tie(x2,y2) = b;
  if(x1+x2<=H&&max(y1,y2)<=W) flag = true;
  else if(max(x1,x2)<=H&&y1+y2<=W) flag = true;
  swap(x2,y2);
  if(x1+x2<=H&&max(y1,y2)<=W) flag = true;
  else if(max(x1,x2)<=H&&y1+y2<=W) flag = true;
  swap(x1,y1);
  if(x1+x2<=H&&max(y1,y2)<=W) flag = true;
  else if(max(x1,x2)<=H&&y1+y2<=W) flag = true;
  swap(x2,y2);
  if(x1+x2<=H&&max(y1,y2)<=W) flag = true;
  else if(max(x1,x2)<=H&&y1+y2<=W) flag = true;

  if(flag==true) maxi = max(maxi,(x1*y1)+(x2*y2));
}

void dfs(vector<pair<int,int>> temp) {
  if(temp.size()==2) {
    cal(temp[0],temp[1]);
    return;
  }
  for(int i=0;i<a.size();i++) {
    if(check[i]==true) continue;
    check[i] = true;
    temp.push_back(a[i]);
    dfs(temp);
    check[i] = false;
    temp.pop_back();
  }
}

int main(int argc, char const *argv[])
{
  int h,w;
  cin >> h >> w;
  H=h;W=w;
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x,y;
    cin >> x >> y;
    a.push_back(make_pair(x,y));
  }
  if(n==1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<pair<int,int>> temp; 
  dfs(temp);

  if(maxi==-1) cout << 0 << '\n';
  else cout << maxi << '\n';
  return 0;
}
