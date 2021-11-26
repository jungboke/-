/*
queue의 메모리크기가 제한되는데, 최대크기를 n개로 두고 n개보다 많이 넣을시, 가장 작은 것보다 크면 가장 작은 것
빼고 그것을 넣음. 가장 큰 수 n개만 구하면 되기 때문에 가능한 문제.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<pow(n,2);i++)
    {
        int x;
        cin >> x;
        if(pq.size()<n) pq.push(x);
        else if(pq.top()<x)
        {
            pq.pop();
            pq.push(x);
        }
    }
    cout << pq.top() << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int,vector<int>,greater<>> pq;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int x;
            cin >> x;
            if(pq.size()==n)
            {
                if(pq.top()>x) continue;
                else if(pq.top()<x)
                {
                    pq.pop();
                    pq.push(x);
                }
            }
            else pq.push(x);
        }
    }
    cout << pq.top() << '\n';
    return 0;
}