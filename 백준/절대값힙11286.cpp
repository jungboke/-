#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
struct cmp
{
    bool operator()(int a,int b)
    {
        if(abs(a)==abs(b)) return (a>b);
        return (abs(a)>abs(b));
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int,vector<int>,cmp> pq;
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        if(x==0)
        {
            if(pq.empty()) cout << 0 << '\n';
            else
            {
                int temp = pq.top();
                pq.pop();
                cout << temp << '\n';
            }
        }
        else pq.push(x);
    }
    return 0;
}
// cumstom priority_queue 만들기, iosbase~cintie~는 모든 cin한번에 모아서 한번에 집어넣음.