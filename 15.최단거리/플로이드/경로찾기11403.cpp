/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dist[101][101];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> dist[i][j];
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]==1&&dist[k][j]==1)
                {
                    dist[i][j] = 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int dist[101][101];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> dist[i][j];     
        }
    }
    for(int c=1;c<=n;c++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][c]==1&&dist[c][j]==1)
                {
                    dist[i][j] = 1;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}