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