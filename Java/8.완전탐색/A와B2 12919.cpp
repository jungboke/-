/*
    순방향재귀는 2의50승이라 시간제한초과함. 다른 재귀법을 생각해하는데 역방향재귀를하면 case를 더줄일수 있음.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string Aerase(string a)
{
    a.pop_back();
    return a;
}
string Berase(string a)
{
    reverse(a.begin(),a.end());
    a.pop_back();
    return a;
}
int dfs(string a,string b)
{
    if(a.size()==b.size())
    {
        if(a==b) return 1;
        else return 0;
    }
    if(b.front()=='A'&&b.back()=='A')
    {
        if(dfs(a,Aerase(b))==1) return 1;
    }
    if(b.front()=='A'&&b.back()=='B') return 0;
    if(b.front()=='B'&&b.back()=='A')
    {
        if(dfs(a,Aerase(b))==1||dfs(a,Berase(b))==1) return 1;
    }
    if(b.front()=='B'&&b.back()=='B')
    {
        if(dfs(a,Berase(b))==1) return 1;
    }
    return 0;
}
int main()
{
    string n,m;
    cin >> n >> m;
    cout << dfs(n,m) << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool flag = false;
// void dfs(string m,string n)
// {
//     if(m.size()==n.size())
//     {
//         if(m==n)
//         {
//             flag = true;
//             return;
//         }
//     }
//     if(m[m.size()-1]=='A')
//     {
//         m.erase(m.end()-1);
//         dfs(m,n);
//         m+='A';
//     }
//     if(m[0]=='B')
//     {
//         reverse(m.begin(),m.end());
//         m.erase(m.end()-1);
//         dfs(m,n);
//         m+='B';
//     }
// }
// int main()
// {
//     string n,m;
//     cin >> n >> m;
//     dfs(m,n);
//     if(flag==true) cout << 1 << '\n';
//     else cout << 0 << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int answer = 0;

void dfs(string s, string t) {
  if(t.size()==s.size()) {
    if(s==t) answer = 1;
    return;
  }
  if(t[t.size()-1]=='A') {
    string temp = t.substr(0,t.size()-1);
    dfs(s,temp);
    if(t[0]=='B') {
      string temp = t.substr(1,t.size()-1);
      reverse(temp.begin(),temp.end());
      dfs(s,temp);
    }
  }
  if(t[t.size()-1]=='B') {
    if(t[0]=='B') {
      string temp = t.substr(1,t.size()-1);
      reverse(temp.begin(),temp.end());
      dfs(s,temp);
    }
  }
}

int main(int argc, char const *argv[])
{
  string s,t;
  cin >> s >> t;
  dfs(s,t);
  cout << answer << '\n';
  return 0;
}