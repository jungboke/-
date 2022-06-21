/*
    직사각형도 정사각형과 같이 90도 rotation가능, 단, N에 유의하고, vector<vector<int>>를 복사
    할 경우, 크기가 다르면 안됨. resize()를 통해 크기 변환후 복사하기.
    Rotate 알고리즘과 배열내 소배열 이동 알고리즘이 필요한 문제.
*/
// 배열내 소배열 이동 정석구현.
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a(m,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            tmp_a[j][n-1-i] = a[i][j];
        }
    }
    a.resize(m,vector<int>(n,0));
    a = tmp_a;
}
void change(vector<vector<int>> &a,vector<vector<int>> b)
{
    int rcnt = 4;
    int n = a.size();
    int m = a[0].size();
    for(int i=0;i<3;i++) rotate(b);
    while(rcnt--)
    {
        rotate(b);
        vector<pair<int,int>> b2;
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[0].size();j++)
            {
                if(b[i][j]==1) b2.push_back(make_pair(i,j));
            }
        }
        //for(int i=0;i<b2.size();i++) cout << b2[i].first << b2[i].second << '\n';
        int n2 = b.size();
        int m2 = b[0].size();
        for(int i=0;i<=n-n2;i++)
        {
            for(int j=0;j<=m-m2;j++)
            {
                bool flag = true;
                for(int k=0;k<b2.size();k++)
                {
                    int nx = b2[k].first+i;
                    int ny = b2[k].second+j;
                    if(a[nx][ny]==1)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag==true)
                {
                    for(int k=0;k<b2.size();k++)
                    {
                        int x = b2[k].first+i;
                        int y = b2[k].second+j;
                        a[x][y] = 1;
                    }
                    return;
                }
            }
        }
    }
    return;
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<k;i++)
    {
        int n2,m2;
        cin >> n2 >> m2;
        vector<vector<int>> b(n2,vector<int>(m2,0));
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<m2;j++)
            {
                cin >> b[i][j];
            }
        }
        change(a,b);
        /*
        rotate(b);
        for(int i=0;i<m2;i++)
        {
            for(int j=0;j<n2;j++)
            {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }
        return 0;
        */
/*
    }
     int answer = 0;
     for(int i=0;i<n;i++)
     {
         for(int j=0;j<m;j++)
         {
             if(a[i][j]==1) answer++;
         }
     }
     cout << answer << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int a[41][41];
// int N,M;
// void rotate(vector<vector<int>> &a)
// {
//     int n = a.size();
//     int m = a[0].size(); 
//     vector<vector<int>> tmp_a(m,vector<int>(n,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             tmp_a[j][n-i-1] = a[i][j];
//         }
//     }
//     a.resize(m,vector<int>(n,0));
//     a = tmp_a;
// }
// bool change(vector<vector<int>> temp)
// {
//     int n = temp.size();
//     int m = temp[0].size();
//     for(int c=0;c<N-n+1;c++)
//     {
//         for(int d=0;d<M-m+1;d++)
//         {
//             bool flag = true;
//             for(int i=0;i<n;i++)
//             {
//                 for(int j=0;j<m;j++)
//                 {
//                     if(temp[i][j]==0) continue;
//                     if(a[i+c][j+d]==1)
//                     {
//                         flag = false;
//                     }
//                 }
//             }
//             if(flag==true)
//             {
//                 for(int i=0;i<n;i++)
//                 {
//                     for(int j=0;j<m;j++)
//                     {
//                         if(temp[i][j]==0) continue;
//                         a[i+c][j+d] = temp[i][j];
//                     }
//                 }
//                 return true;
//             }
//         }
//     }
//     return false;
// }
// int main()
// {
//     int n,m,k;
//     cin >> n >> m >> k;
//     N=n;M=m;
//     for(int c=0;c<k;c++)
//     {
//         int x,y;
//         cin >> x >> y;
//         vector<vector<int>> temp(x,vector<int>(y,0));
//         for(int i=0;i<x;i++)
//         {
//             for(int j=0;j<y;j++)
//             {
//                 cin >> temp[i][j];
//             }
//         }
//         for(int i=0;i<3;i++) rotate(temp);
//         for(int i=0;i<4;i++)
//         {
//             rotate(temp);
//             bool flag = change(temp);
//             if(flag==true) break;
//         }
//     }
//     int answer = 0;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             if(a[i][j]==1) answer++;
//         }
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> a;
int board[41][41];
int N,M;

void rotate(vector<vector<int>> &v) {
  int x = v.size();
  int y = v[0].size();
  vector<vector<int>> tmp_v(y,vector<int>(x,0));
  for(int i=0;i<x;i++) {
    for(int j=0;j<y;j++) {
      tmp_v[j][x-i-1] = v[i][j];
    }
  }
  v.resize(y,vector<int>(x,0));
  v = tmp_v;
}

void stick(vector<vector<int>> v) {
  for(int k=0;k<3;k++) rotate(v);
  for(int k=0;k<4;k++) {
    rotate(v);
    int x = v.size();
    int y = v[0].size();
    for(int c=0;c<N-x+1;c++) {
      for(int d=0;d<M-y+1;d++) {
        bool flag = true;
        for(int i=0;i<x;i++) {
          for(int j=0;j<y;j++) {
            if(v[i][j]==1&&board[i+c][j+d]==1) flag = false;
          }
        }
        if(flag==true) {
          for(int i=0;i<x;i++) {
            for(int j=0;j<y;j++) {
              if(v[i][j]==1) board[i+c][j+d] = 1;
            }
          }
          return;
        }
      } 
    }
  }
}

int main(int argc, char const *argv[])
{
  int n,m,k;
  cin >> n >> m >> k;
  N=n;M=m;
  for(int c=0;c<k;c++) {
    int x,y;
    cin >> x >> y;
    vector<vector<int>> temp(x,vector<int>(y,0));
    for(int i=0;i<x;i++) {
      for(int j=0;j<y;j++) {
        cin >> temp[i][j];
      }
    }
    a.push_back(temp);
  }
  for(int i=0;i<a.size();i++) {
    stick(a[i]);
  }
  int answer = 0;
  for(int i=0;i<N;i++) {
    for(int j=0;j<M;j++) {
      if(board[i][j]==1) answer+=1;
    }
  }
  cout << answer << '\n';
  return 0;
}
