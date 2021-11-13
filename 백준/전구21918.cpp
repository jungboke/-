#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(x==1)
        {
            a[y-1] = z;
        }
        else if(x==2)
        {
            for(int j=y-1;j<=z-1;j++)
            {
                a[j] = 1 - a[j];
            }
        }
        else if(x==3)
        {
            for(int j=y-1;j<=z-1;j++)
            {
                a[j] = 0;
            }
        }
        else if(x==4)
        {
            for(int j=y-1;j<=z-1;j++)
            {
                a[j] = 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}