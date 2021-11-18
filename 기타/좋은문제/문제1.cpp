#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void Print(vector<int> a)
{
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << ' ';
    }
    cout << '\n';
}
bool check(vector<int> a,int m)
{
    for(int i=1;i<=a.size()-2;i++)
    {
        if(i<=m) continue;
        if(a[i+1]!=a[i]) return false;
    }
    return true;
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    int cnt = 0;
    int day = 0;
    while(true)
    {
        //flag = false;
        sort(a.begin(),a.end());
        int mini = 10000000;
        int idx = 0;
        //if(check(a,m)==false) flag = true;
        for(int i=1;i<=n;i++)
        {
            if(i<=m) continue;
            if(a[i]-a[i-m]<mini&&a[i]-a[i-m]>0)
            {
                mini = a[i]-a[i-m];
                idx = i;
            }
        }
        if(mini==10000000) break;
        a[idx] -= mini;
        cnt += mini;
        day++;
        //Print(a);
    }
    cout << cnt << ' ' << day << '\n';
    return 0;
}