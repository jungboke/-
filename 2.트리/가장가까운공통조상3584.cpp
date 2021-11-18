#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
vector<int> a[10001];
bool check[10001];
int dfs(int num,int target,vector<int> &result)
{
    if(num==target)
    {
        result.push_back(num);
        return -1;
    }
    check[num] = true;
    for(auto k:a[num])
    {
        if(check[k]==false)
        {
            result.push_back(num);
            if(dfs(k,target,result)==-1) return -1;
            result.pop_back();
        }
    }
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> target;
        int n;
        cin >> n;
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin >> x >> y;
            a[x].push_back(y);
            target.push_back(y);
        }
        int root = 0;
        for(int i=1;i<=n;i++)
        {
            if(find(target.begin(),target.end(),i)==target.end())
            {
                root = i;
                break;
            }
        }
        vector<int> result1;
        vector<int> result2;
        int x1,x2;
        cin >> x1 >> x2;
        dfs(root,x1,result1);
        memset(check,false,sizeof(check));
        dfs(root,x2,result2);
        int answer = 0;
        int m = min(result1.size(),result2.size());
        for(int i=0;i<m;i++)
        {
            if(result1[i]==result2[i])
            {
                answer = result1[i];
            }
        }
        cout << answer << '\n';
        for(int i=1;i<=n;i++)
        {
            a[i].clear();
        }
        memset(check,false,sizeof(check));
    }
    return 0;
}
// 다음에는 LCA알고리즘 사용해서 풀어보기.