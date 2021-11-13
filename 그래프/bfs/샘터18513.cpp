#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
int dx[] = {-1,1};
int main()
{
    int n,m;
    cin >> n >> m;
    queue<int> q;
    set<int> s;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        q.push(x);
        s.insert(x);
    }
    int dis = 0;
    long long answer = 0;
    int cnt = 0;
    while(!q.empty())
    {
        int size = q.size();
        dis++;
        for(int i=0;i<size;i++)
        {
            int x = q.front();
            q.pop();
            for(int j=0;j<2;j++)
            {
                int nx = x+dx[j];
                if(s.count(nx)==0)
                {
                    q.push(nx);
                    s.insert(nx);
                    answer += dis;
                    cnt++;
                    if(cnt==m)
                    {
                        cout << answer << '\n';
                        return 0;
                    }          
                }
            }
        }
    }
    return 0;
}
/*
    완전탐색->이분탐색->bfs순으로 풀이법을 유추할수 있어야함.
    bfs를 쓰는데 집의 범위가 주어져있지 않으므로, check배열을 쓰지 않고 set을 사용함.
    또한 dist배열에 거리를 담고 마지막에 다더하는게 아닌 집을 놓는 상황마다 정답에
    거리를 추가해야하므로, while(!q.empty())내에서도 q.size()만큼 돌리고 넘어가면
    dist에 +1을 해주는 식으로 생각해야함.
    뱀과사다리 게임과 해당문제 같은 이분탐색과 비슷한 모형의 문제에서 bfs를 생각하지 못함.
*/