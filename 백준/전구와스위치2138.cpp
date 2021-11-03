#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int N;
void change(string &a,int n)
{
    if(a[n-1]=='1') a[n-1] = '0';
    else a[n-1] = '1';
    if(a[n]=='1') a[n] = '0';
    else a[n] = '1';
    if(a[n+1]=='1') a[n+1] = '0';
    else a[n+1] = '1';
}
int go(string a,string b)
{
    int cnt = 0;
    for(int i=0;i<N-1;i++)
    {
        if(a[i]!=b[i])
        {
            cnt++;
            change(a,i+1);
        }
    }
    if(a==b) return cnt;
    else return -1;
}
int main()
{
    int n;
    cin >> n;
    N=n;
    string a;
    cin >> a;
    string b;
    cin >> b;
    if(go(a,b)!=-1)
    {
        cout << go(a,b) << '\n';
        return 0;
    }
    if(a[0]=='0') a[0] = '1';
    else a[0] = '0';
    if(a[1]=='0') a[1] = '1';
    else a[1] = '0'; 
    if(go(a,b)!=-1)
    {
        cout << go(a,b)+1 << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}