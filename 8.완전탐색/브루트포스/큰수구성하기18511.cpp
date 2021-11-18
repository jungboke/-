/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> result;
void dfs(vector<int> a,int cnt,string s,int sum)
{
    if(cnt==s.size())
    {
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(sum*10+a[i]<=stoi(s))
            result.push_back(sum*10+a[i]);
        dfs(a,cnt+1,s,sum*10+a[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    string str_n = to_string(n);
    int k;
    cin >> k;
    vector<int> a;
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    dfs(a,0,str_n,0);
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int maxi = 0;
void go(vector<int> a,vector<int> temp,int target,int max)
{
    if(temp.size()>max)
    {
        return;
    }
    int num = 0;
    for(int i=0;i<temp.size();i++)
    {
        num = num*10 + temp[i];
    }
    if(num<=target)
    {
        if(maxi<num) maxi = num;
    }
    for(int i=0;i<a.size();i++)
    {
        temp.push_back(a[i]);
        go(a,temp,target,max);
        temp.pop_back();
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    string str_n = to_string(n);
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    vector<int> temp;
    go(a,temp,n,str_n.size());
    cout << maxi << '\n';
    return 0;
}






















