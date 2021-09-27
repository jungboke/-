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
/*
    순방향재귀는 2의50승이라 시간제한초과함. 다른 재귀법을 생각해하는데 역방향재귀를하면 case를 더줄일수 있음.
*/