/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int check(vector<vector<char>> a)
{
    int maxi = 1;
    for(int i=0;i<a.size();i++)
    {
        int cnt = 1;
        for(int j=1;j<a[i].size();j++)
        {
            if(a[i][j-1]==a[i][j]) cnt++;
            else cnt=1;

            if(maxi<cnt) maxi = cnt;
        }
        
    }
    for(int i=0;i<a[0].size();i++)
    {
        int cnt = 1;
        for(int j=1;j<a.size();j++)
        {
            if(a[j-1][i]==a[j][i]) cnt++;
            else cnt=1;

            if(maxi<cnt) maxi = cnt;
        }
    }
    return maxi;
}
int main(){

    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n,'0'));
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<n;j++)
        {
            a[i][j] = temp[j] - 48;
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
                int k = check(a);
                if(maxi<k) maxi = k;
                swap(a[i][j],a[i][j+1]);
            }
            if(i+1<n)
            {
                swap(a[i][j],a[i+1][j]);
                int k = check(a);
                if(maxi<k) maxi = k;
                swap(a[i][j],a[i+1][j]);
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}
// swap함수를 이용한 배열인자 바꾸기, 연속되는 최대수 구하는 알고리즘
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int check(vector<vector<char>> a)
{
    int n = a.size();
    int maxi = 0;
    for(int i=0;i<n;i++)
    {
        int cnt = 1;
        for(int j=0;j<n-1;j++)
        {
            if(a[i][j]==a[i][j+1]) cnt++;
            else cnt = 1;

            if(maxi<cnt) maxi = cnt;
        }
    }
    for(int j=0;j<n;j++)
    {
        int cnt = 1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i][j]==a[i+1][j]) cnt++;
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
    vector<vector<char>> a(n,vector<char>(n,'0'));
    for(int i=0;i<n;i++)
    {
        string temp;
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
                int m = check(a);
                if(maxi<m) maxi = m;
                swap(a[i][j],a[i][j+1]);
            }
            if(i+1<n)
            {
                swap(a[i][j],a[i+1][j]);
                int m = check(a);
                if(maxi<m) maxi = m;
                swap(a[i][j],a[i+1][j]);
            }
        }
    }
    cout << maxi << '\n';
    return 0;
}






















