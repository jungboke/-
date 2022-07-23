/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int sum[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    cin >> a[0];
    sum[0] = a[0];
    for(int i=1;i<n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        int answer;
        if(x==1) answer = sum[y-1];
        else answer = sum[y-1] - sum[x-2];
        cout << answer << '\n';
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int check[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    check[0] = a[0];
    for(int i=1;i<n;i++)
    {
        check[i] = check[i-1] + a[i];
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        x-=1;y-=1;
        if(x==0) cout << check[y] << '\n';
        else cout << check[y]-check[x-1] << '\n';
    }
    return 0;
}