/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dist[501][501];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
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
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(dist[x][y]>z)
        {
            cout << "Stay here" << '\n';
        }
        else cout << "Enjoy other party" << '\n';
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int dist[501][501];
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n;j++)
//         {
//             cin >> dist[i][j];
//         }
//     }
//     for(int c=1;c<=n;c++)
//     {
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 if(dist[i][j]>dist[i][c]+dist[c][j])
//                 {
//                     dist[i][j] = dist[i][c]+dist[c][j];
//                 }
//             }
//         }
//     }
//     for(int i=0;i<m;i++)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         if(dist[x][y]<=z) cout << "Enjoy other party" << '\n';
//         else cout << "Stay here" << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[501][501];

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=1;i<=n;i++) {
    for(int j=1;j<=n;j++) {
      cin >> a[i][j];
    }
  }
  for(int c=1;c<=n;c++) {
    for(int i=1;i<=n;i++) {
      for(int j=1;j<=n;j++) {
        if(a[i][j]>a[i][c]+a[c][j]) {
          a[i][j] = a[i][c]+a[c][j];
        }
      }
    }
  }
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    if(a[x][y]>z) {
      cout << "Stay here" << '\n';
    } else cout << "Enjoy other party" << '\n';
  }
  return 0;
}
