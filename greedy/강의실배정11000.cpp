#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> a;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        a.push_back(make_pair(x,y));
    }
    sort(a.begin(),a.end());
    priority_queue<int,vector<int>,greater<>> pq;
    pq.push(a[0].second);
    for(int i=1;i<n;i++)
    {
        if(a[i].first>=pq.top())
        {
            pq.pop();
            pq.push(a[i].second);
        }
        else pq.push(a[i].second);
    }
    cout << pq.size() << '\n';
    return 0;
}
/*
    강의시작시간을 오름차순으로 정렬한뒤, 강의를 추가할때 현재 강의중 가장 일찍 끝나는 것
    뒤에 추가해야 하므로, 우선순위큐 사용.
    
    시작시간,끝시간이 정해진 그래프들을 겹치지 않게 합쳐서 최소로 만들때 유용할듯.
*/