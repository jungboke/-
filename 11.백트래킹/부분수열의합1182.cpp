/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
void dfs(vector<int> a,int idx,int sum,int target)
{
    if(idx==a.size())
    {
        if(sum==target) answer++;
        return;
    }
    dfs(a,idx+1,sum+a[idx],target);
    dfs(a,idx+1,sum,target);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    dfs(a,0,0,m);
    if(m==0) answer-=1;
    cout << answer << '\n';
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
void dfs(vector<int> a,int idx,int sum,int max)
{
    if(idx==a.size())
    {
        if(sum==max) answer++;
        return;
    }
    dfs(a,idx+1,sum+a[idx],max);
    dfs(a,idx+1,sum,max);
}
int main()
{
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    dfs(a,0,0,s);
    if(s==0) cout << answer-1 << '\n';
    else cout << answer << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int answer = 0;
void dfs(vector<int> a,int idx,int sum,int target)
{
    if(idx==a.size())
    {
        if(sum==target) answer+=1;
        return;
    }
    dfs(a,idx+1,sum+a[idx],target);
    dfs(a,idx+1,sum,target);
}
int main()
{
    int n,s;
    cin >> n >> s;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    dfs(a,0,0,s);
    if(s==0) answer -= 1;
    cout << answer << '\n';
    return 0;
}














