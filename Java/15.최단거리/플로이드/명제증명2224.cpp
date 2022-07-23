/*
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
*/
// #include <bits/stdc++.h>
// using namespace std;
// int dist[100][100];
// int main()
// {
//     int n;
//     cin >> n;
//     cin.ignore();
//     int cnt = 0;
//     for(int i=0;i<n;i++)
//     {
//         string temp = "";
//         getline(cin,temp);
//         char x = temp[0];
//         char y = temp[temp.size()-1];
//         dist[x-'A'][y-'A'] = 1;
//     }
//     for(int c=0;c<=99;c++)
//     {
//         for(int i=0;i<=99;i++)
//         {
//             for(int j=0;j<=99;j++)
//             {
//                 if(dist[i][c]==1&&dist[c][j]==1)
//                 {
//                     dist[i][j] = 1;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<=99;i++)
//     {
//         for(int j=0;j<=99;j++)
//         {
//             if(dist[i][j]==1)
//             { 
//                 if(i==j) dist[i][j] = 0;
//                 else cnt++;
//             }
//         }
//     }
//     cout << cnt << '\n';
//     for(int i=0;i<=99;i++)
//     {
//         for(int j=0;j<=99;j++)
//         {
//             if(dist[i][j]==1)
//             {
//                 cout << char(i+'A') << " => " << char(j+'A') << '\n';
//             }
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[60][60];

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  cin.ignore();
  for(int i=0;i<n;i++) {
    string x;
    getline(cin,x);
    int start = x[0]-'A';
    int end = x[x.size()-1]-'A';
    a[start][end] = 1;
  }
  for(int c=0;c<60;c++) {
    for(int i=0;i<60;i++) {
      for(int j=0;j<60;j++) {
        if(a[i][c]==1&&a[c][j]==1) {
          a[i][j] = 1;
        }
      }
    }
  }
  int answer = 0;
  for(int i=0;i<60;i++) {
    for(int j=0;j<60;j++) {
      if(i==j) continue;
      if(a[i][j]==1) answer+=1; 
    }
  }
  cout << answer << '\n';
  for(int i=0;i<60;i++) {
    for(int j=0;j<60;j++) {
      if(i==j) continue;
      if(a[i][j]==1) {
        cout << char('A'+i) << " => " << char('A'+j) << '\n';
      }
    }
  }
  return 0;
}