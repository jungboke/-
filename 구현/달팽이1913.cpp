/*#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c;
    cin >> c;
    int x,y;
    vector<vector<int>> a(n,vector<int>(n,0));
    int m = n/2;
    auto now = make_pair(m,m);
    int num = 1;
    int how = 2;
    a[m][m] = num++;
    while(!(now.first==0&&now.second==0))
    {
        int x = now.first;
        int y = now.second;
        for(int i=0;i<how;i++)
        {
            a[x-1][y+i] = num++;
        }
        for(int i=0;i<how;i++)
        {
            a[x+i][y+how-1] = num++;
        }
        for(int i=0;i<how;i++)
        {
            a[x+how-1][y+how-2-i] = num++;
        }
        for(int i=0;i<how;i++)
        {
            a[x+how-2-i][y-1] = num++;
        }
        how+=2;
        now = make_pair(now.first-1,now.second-1);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << a[i][j] << ' ';
            if(a[i][j]==c)
            {
                x = i;
                y = j;
            }
        }
        cout << '\n';
    }
    cout << x+1 << ' ' << y+1 << '\n';
    return 0;
}*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(n,0));
    int start = n/2;
    int cnt = 1;
    a[start][start] = cnt++;
    int k = 2;
    while(start>0)
    {
        for(int j=start;j<start+k;j++)
        {
            a[start-1][j] = cnt++;
        }
        for(int i=start;i<start+k;i++)
        {
            a[i][start+k-1] = cnt++;
        }
        for(int j=start+k-2;j>start-2;j--)
        {
            a[start+k-1][j] = cnt++;
        }
        for(int i=start+k-2;i>start-2;i--)
        {
            a[i][start-1] = cnt++;
        }
        start-=1;
        k+=2;
    }
    int x,y;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << a[i][j] << ' ';
            if(a[i][j]==m)
            {
                x = i; y = j;
            }
        }
        cout << '\n';
    }
    cout << x+1 << ' ' <<  y+1 << '\n';
    return 0;
}
// 달팽이모양 패턴을 간결하게 분석하는게 중요함.