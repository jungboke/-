#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#define MAX 999999999;
using namespace std;
int dist[100001];
int main()
{
    for(int i=0;i<100001;i++)
    {
        dist[i] = MAX;
    }
    int n,k;
    cin >> n >> k;
    queue<int> q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x-1>=0&&x-1<=100000&&dist[x-1]>dist[x]+1)
        {
            q.push(x-1);
            dist[x-1] = dist[x] + 1;
        }
        if(x+1>=0&&x+1<=100000&&dist[x+1]>dist[x]+1)
        {
            q.push(x+1);
            dist[x+1] = dist[x] + 1;
        }
        if(2*x>=0&&2*x<=100000&&dist[2*x]>dist[x])
        {
            q.push(2*x);
            dist[2*x] = dist[x];
        }
    }
    cout << dist[k] << '\n';
    return 0;
}