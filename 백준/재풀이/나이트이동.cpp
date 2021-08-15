#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <tuple>
#include <queue>
using namespace std;
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int check[301][301];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(check,-1,sizeof(check));
        int n;
        cin >> n;
        int a,b;
        cin >> a >> b;
        int c,d;
        cin >> c >> d;
        queue<pair<int,int>> q;
        q.push(make_pair(a,b));
        check[a][b] = 0;
        while(!q.empty())
        {
            int x,y;
            tie(x,y) = q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx>=0&&nx<n&&ny>=0&&ny<n&&check[nx][ny]==-1)
                {
                    q.push(make_pair(nx,ny));
                    check[nx][ny] = check[x][y]+1;
                }
            }
        }
        cout << check[c][d] << '\n';
    }

    return 0;
}