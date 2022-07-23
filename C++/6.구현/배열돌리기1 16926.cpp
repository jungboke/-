/*
    배열을 한칸씩 회전하는 전형적인 방법. 왠만하면 바깥에서 안으로 들어가고 회전을 4분할로 나누어서 생각하기.
    배열90도 회전이랑은 다름.
*/
/*
  배열 회전문제를 풀때, 임시배열을 사용하던 기존 방식말고,
  임시배열을 생성하지 않고, 기존배열로만 회전시키는 방법이 있음.
  이때, 배열의 첫칸 값을 temp로 저장한 뒤, 마지막에 사용해줌.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void rotate(vector<vector<int>> &a)
{
    int n = a.size();
    int m = a[0].size();
    vector<vector<int>> tmp_a = a;
    int x = min(n,m);
    int cnt = x/2;
    for(int c=0;c<cnt;c++)
    {
        for(int i=0+c;i<n-1-c;i++)
        {
            tmp_a[i+1][0+c] = a[i][0+c]; 
        }
        for(int j=0+c;j<m-1-c;j++)
        {
            tmp_a[n-1-c][j+1] = a[n-1-c][j];
        }
        for(int i=n-1-c;i>0+c;i--)
        {
            tmp_a[i-1][m-1-c] = a[i][m-1-c];
        }
        for(int j=m-1-c;j>0+c;j--)
        {
            tmp_a[0+c][j-1] = a[0+c][j];
        }
    }
    a = tmp_a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> a[i][j];
        }
    }
    while(r--) rotate(a);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// void rotate(vector<vector<int>> &a)
// {
//     int n = a.size();
//     int m = a[0].size();
//     vector<vector<int>> tmp_a(n,vector<int>(m,0));
//     int k = min(n,m)/2;
//     for(int c=0;c<k;c++)
//     {
//         for(int i=0+c;i<n-1-c;i++)
//         {
//             tmp_a[i+1][c] = a[i][c];
//         }
//         for(int j=0+c;j<m-1-c;j++)
//         {
//             tmp_a[n-1-c][j+1] = a[n-1-c][j];
//         }
//         for(int i=n-1-c;i>0+c;i--)
//         {
//             tmp_a[i-1][m-1-c] = a[i][m-1-c];
//         }
//         for(int j=m-1-c;j>0+c;j--)
//         {
//             tmp_a[0+c][j-1] = a[0+c][j];
//         }
//     }
//     a = tmp_a;
// }
// int main()
// {
//     int n,m,r;
//     cin >> n >> m >> r;
//     vector<vector<int>> a(n,vector<int>(m,0));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     while(r--) rotate(a);
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cout << a[i][j] << ' ';
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[301][301];

void spin(int x, int y, int col, int row) {
  int temp = a[x][y];
  for(int j=y;j<y+row-1;j++) {
    a[x][j] = a[x][j+1];
  }
  for(int i=x;i<x+col-1;i++) {
    a[i][y+row-1] = a[i+1][y+row-1];
  }
  for(int j=y+row-1;j>y;j--) {
    a[x+col-1][j] = a[x+col-1][j-1];
  }
  for(int i=x+col-1;i>x;i--) {
    a[i][y] = a[i-1][y];
  }
  a[x+1][y] = temp;
}

int main(int argc, char const *argv[])
{
  int n,m,r;
  cin >> n >> m >> r;
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cin >> a[i][j];
    }
  }
  int col = n;
  int row = m;
  int x = 0;
  int y = 0;
  while(col>=2&&row>=2) {
    for(int i=0;i<r;i++) spin(x,y,col,row);
    col-=2;
    row-=2;
    x+=1;
    y+=1;
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
