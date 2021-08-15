#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int go(vector<vector<char>> a)
{
    int n = a.size();
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        int cnt = 1;
        for(int j=0;j<n-1;j++)
        {
            if(a[i][j] == a[i][j+1]) cnt++;
            else cnt = 1;

            if(maxi<cnt) maxi = cnt;
        }
    }
    for(int j=0;j<n;j++)
    {
        int cnt = 1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i][j] == a[i+1][j]) cnt++;
            else cnt = 1;

            if(maxi<cnt) maxi = cnt;
        }
    }
    return maxi;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n,0));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<n;j++)
        {
            a[i][j] = temp[j];
        }
    }
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j+1<n)
            {
                swap(a[i][j],a[i][j+1]);
                if(maxi<go(a)) maxi = go(a);
                swap(a[i][j],a[i][j+1]);
            }
            if(i+1<n)
            {
                swap(a[i][j],a[i+1][j]);
                if(maxi<go(a)) maxi = go(a);
                swap(a[i][j],a[i+1][j]);
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}