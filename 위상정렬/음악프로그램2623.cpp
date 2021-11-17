// 1 4 3 을 가져왔다면 1 4, 4 3 처럼 ind[]배열 생성하기
// 위상 정렬
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[1001];
int ind[1001];
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        vector<int> temp;
        int x;
        cin >> x;
        for(int j=0;j<x;j++)
        {
            int y;
            cin >> y;
            temp.push_back(y);
        }
        for(int j=1;j<temp.size();j++)
        {
            int x = temp[j-1];
            int y = temp[j];
            a[x].push_back(y);
            ind[y]++;
        }
    }
    vector<int> result;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0) q.push(i); 
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        result.push_back(x);
        for(auto k:a[x])
        {
            ind[k]--;
            if(ind[k]==0)
            {
                q.push(k);
            }
        }
    }
    if(result.size()!=n) cout << 0 << '\n';
    else
    {
        for(int i=0;i<result.size();i++)
        {
            cout << result[i] << '\n';
        }
    }
    return 0;
}