#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        multiset<int> ms;
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            string x;
            cin >> x;
            int num;
            cin >> num;
            if(x[0]=='I')
            {
                ms.insert(num);
            }
            else if(x[0]=='D'&&!ms.empty())
            {
                if(num==1)
                {
                    auto it = ms.end();
                    it--;
                    ms.erase(it);
                }
                else if(num==-1)
                {
                    ms.erase(ms.begin());
                }
            }
        }
        if(ms.size()==0) cout << "EMPTY" << '\n';
        else
        {
            auto it = ms.end();
            it--;
            cout << *it << ' ' << *ms.begin() << '\n';
        }
    }
    return 0;
}
// 반복자 사칙연산을 하려면 vector,deque만 가능.
// list,set,map은 반복자 사칙연산이 ++,--만 가능. why) 두 반복자 유형이 다름.