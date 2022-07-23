#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
vector<int> a[10001];
int ind[10001];
int work[10001];
int time[10001];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin >> x >> y;
        work[i] = x;
        for(int j=0;j<y;j++)
        {
            int z;
            cin >> z;
            a[z].push_back(i);
            ind[i] += 1;
        }
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(ind[i]==0)
        {
            q.push(i);
            time[i] = work[i];
        }
    }
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        for(int i=0;i<a[x].size();i++)
        {
            int y = a[x][i];
            ind[y] -= 1;
            if(time[y]<time[x]+work[y]) time[y] = time[x]+work[y];
            if(ind[y]==0)
            {
                q.push(y);
            }
        }
    }
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        if(answer<time[i]) answer = time[i];
    }
    cout << answer << '\n'; 
    return 0;
}
/*
    선행되어야 하는 작업들이 모두 끝나야(ind==0) 다음 작업을 할수 있고, 선행작업들마다 최소시간이 다름을 확인해야함.
*/