#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a = a;
    int x = min(n,m);
    int cnt = x/2;
    for(int c=0;c<cnt;c++)
    {
        for(int i=0+c;i<n-1-c;i++)
        {
            tmp_a[i+1][0+c] = a[i][0+c]; 
        }
        for(int j=0+c;j<m-1-c;j++)
        {
            tmp_a[n-1-c][j+1] = a[n-1-c][j];
        }
        for(int i=n-1-c;i>0+c;i--)
        {
            tmp_a[i-1][m-1-c] = a[i][m-1-c];
        }
        for(int j=m-1-c;j>0+c;j--)
        {
            tmp_a[0+c][j-1] = a[0+c][j];
        }
    }
    a = tmp_a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    while(r--) rotate(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}