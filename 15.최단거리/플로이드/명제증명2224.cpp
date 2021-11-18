#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dist[100][100];
int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    cin.ignore();
    for(int i=0;i<n;i++)
    {
        string temp = "";
        getline(cin,temp);
        dist[temp[0]-'A'][temp[temp.size()-1]-'A'] = 1;
    }
    for(int k=0;k<100;k++)
    {
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                if(dist[i][k]==1&&dist[k][j]==1)
                {
                    dist[i][j] = 1;
                }    
            }
        }
    }
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(dist[i][j]==1)
            { 
                if(i==j) dist[i][j] = 0;
                else cnt++;
            }
        }
    }
    cout << cnt << '\n';
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            if(dist[i][j]==1)
            {
                cout << char(i+'A') << " => " << char(j+'A') << '\n'; 
            }
        }
    }
    return 0;
}