#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    queue<int> q;
    vector<int> result;
    for(int i=1;i<=n;i++)
    {
        q.push(i);
    }
    int cnt = 1;
    while(!q.empty())
    {
        if(cnt==k)
        {
            int x = q.front();
            q.pop();
            result.push_back(x);
            cnt = 1;
            continue;
        }
        int y = q.front();
        q.pop();
        q.push(y);
        cnt++;
    }
    cout << '<';
    for(int i=0;i<result.size();i++)
    {
        cout << result[i];
        if(i==result.size()-1) cout << '>' << '\n';
        else cout << ", ";
    }
    return 0;
}