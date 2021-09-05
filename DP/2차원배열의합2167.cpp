#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int sum[301][301];
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    sum[0][0] = a[0][0];
    for(int j=1;j<m;j++)
    {
        sum[0][j] = sum[0][j-1] + a[0][j];
    }
    for(int i=1;i<n;i++)
    {
        sum[i][0] = sum[i-1][0] + a[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j]; 
        }
    }
    int t;
    cin >> t;
    while(t--)
    {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 -= 1; y1 -= 1; x2 -= 1; y2 -= 1;
        if(x1==0)
        {
            cout << sum[x2][y2] - sum[x2][y1-1]  << '\n';
        }
        else if(y1==0)
        {
            cout << sum[x2][y2] - sum[x1-1][y2] << '\n';
        }
        else cout << sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1] << '\n';
    }
    return 0;
}
// 그냥 index-1 하지말자.