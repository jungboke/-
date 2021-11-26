/*
    메모리의 한계가 극단적으로 낮아 for문에서도 변수생성이 안됨.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<pair<int,int>> dq;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        dq.push_back(make_pair(x,i+1));
    }
    while(!dq.empty())
    {
        auto p = dq.front();
        dq.pop_front();
        cout << p.second << ' ';
        if(p.first>0)
        {
            for(int i=0;i<p.first-1;i++)
            {
                dq.push_back(make_pair(dq.front().first,dq.front().second));
                dq.pop_front();
            }
        }
        else if(p.first<0)
        {
            for(int i=0;i<-p.first;i++)
            {
                dq.push_front(make_pair(dq.back().first,dq.back().second));
                dq.pop_back();
            }
        }
    }
    cout << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<pair<int,int>> dq;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        dq.push_back(make_pair(x,i+1));
    }
    for(int i=0;i<n;i++)
    {
        auto p = dq.front();
        cout << p.second << ' ';
        dq.pop_front();
        int x = p.first;
        if(x>0)
        {
            for(int j=0;j<x-1;j++)
            {
                dq.push_back(make_pair(dq.front().first,dq.front().second));
                dq.pop_front();
            }
        }
        else
        {
            for(int j=0;j<abs(x);j++)
            {
                dq.push_front(make_pair(dq.back().first,dq.back().second));
                dq.pop_back();
            }
        }
    }
    return 0;
}