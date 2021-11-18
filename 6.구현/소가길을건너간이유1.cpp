#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,int> m;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        if(m[x]==0) m[x] = y+1;
        else
        {
            if(m[x]!=y+1)
            {
                m[x] = y+1;
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}