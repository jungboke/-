/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[30];
void change(int num,vector<vector<int>> a,vector<vector<int>> &color)
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[i][j]==num)
            {
                color[i][j] = 1;
            }
        }
    }
}
bool bingo(vector<vector<int>> color)
{
    int result = 0;
    for(int i=0;i<5;i++)
    {
        int cnt = 0;
        for(int j=0;j<5;j++)
        {
            if(color[i][j]==1) cnt++;
        }
        if(cnt==5) result++;
    }
    for(int j=0;j<5;j++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            if(color[i][j]==1) cnt++;
        }
        if(cnt==5) result++;
    }
    for(int m=0;m<=8;m++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(i+j==m&&color[i][j]==1) cnt++;
            }
        }
        if(cnt==5) result++;
    }
    for(int m=0;m<=8;m++)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            for(int j=0;j<5;j++)
            {
                if(j-i+4==m&&color[i][j]==1) cnt++;
            }
        }
        if(cnt==5) result++;
    }
    if(result>=3) return true;
    else return false;
}
int main()
{
    vector<vector<int>> a(5,vector<int>(5,0));
    vector<vector<int>> color(5,vector<int>(5,0));
    vector<vector<int>> call(5,vector<int>(5,0));
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin >> call[i][j];
        }
    }
    int cnt = 0;
    bool flag = true;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cnt++;
            change(call[i][j],a,color);
            if(bingo(color)==true)
            {
                flag = false;
                break;
            }
        }
        if(flag==false) break;
    }
    cout << cnt << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// bool bingo(vector<vector<int>> color)
// {
//     int result = 0;
//     // 가로
//     for(int i=0;i<5;i++)
//     {
//         int cnt = 0;
//         for(int j=0;j<5;j++)
//         {
//             if(color[i][j]==1) cnt++;
//         }
//         if(cnt==5) result++;
//     }
//     // 세로
//     for(int j=0;j<5;j++)
//     {
//         int cnt = 0;
//         for(int i=0;i<5;i++)
//         {
//             if(color[i][j]==1) cnt++;
//         }
//         if(cnt==5) result++;
//     }
//     // 우상향대각
//     int cnt = 0;
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             if(i+j==4)
//             {
//                 if(color[i][j]==1) cnt++;
//             }
//         }
//     }
//     if(cnt==5) result++;
//     // 우하향대각
//     cnt = 0;
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             if(i-j==0)
//             {
//                 if(color[i][j]==1) cnt++;
//             }
//         }
//     }
//     if(cnt==5) result++;

//     if(result>=3) return true;
//     else return false;
// }
// void change(vector<vector<int>> &color,vector<vector<int>> a,int num)
// {
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             if(a[i][j]==num)
//             {
//                 color[i][j] = 1;
//                 break;
//             }
//         }
//     }
// }
// int main()
// {
//     vector<vector<int>> a(5,vector<int>(5,0));
//     vector<vector<int>> answers(5,vector<int>(5,0));
//     vector<vector<int>> color(5,vector<int>(5,0));
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     int answer = 0;
//     int cnt = 1;
//     for(int i=0;i<5;i++)
//     {
//         for(int j=0;j<5;j++)
//         {
//             cin >> answers[i][j];
//             change(color,a,answers[i][j]);
//             if(answer==0)
//             {
//                 if(bingo(color)==true)
//                     answer = cnt;
//             }
//             cnt++;
//         }
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[5][5];
bool check[5][5];
void bingo_call(int x) {
  for(int i=0;i<5;i++) {
    for(int j=0;j<5;j++) {
      if(a[i][j]==x) {
        check[i][j] = true;
        return;
      }
    }
  }
}

int bingo_check() {
  int cnt = 0;
  for(int i=0;i<5;i++) {
    bool flag = true;
    for(int j=0;j<5;j++) {
      if(check[i][j]==false) flag = false;
    }
    if(flag==true) cnt+=1;
  }
  for(int j=0;j<5;j++) {
    bool flag = true;
    for(int i=0;i<5;i++) {
      if(check[i][j]==false) flag = false;
    }
    if(flag==true) cnt+=1;
  }
  for(int c=0;c<1;c++) {
    bool flag = true;
    for(int i=0;i<5;i++) {
      for(int j=0;j<5;j++) {
        if(i-j==0) {
          if(check[i][j]==false) flag = false;
        }
      }
    }
    if(flag==true) cnt+=1;
  }
  for(int c=0;c<1;c++) {
    bool flag = true;
    for(int i=0;i<5;i++) {
      for(int j=0;j<5;j++) {
        if(i+j==4) {
          if(check[i][j]==false) flag = false;
        }
      }
    }
    if(flag==true) cnt+=1;
  }
  return cnt;
}

int main(int argc, char const *argv[])
{
  for(int i=0;i<5;i++) {
    for(int j=0;j<5;j++) {
      cin >> a[i][j];
    }
  }
  int answer = -1;
  int cnt = 1;
  for(int i=0;i<5;i++) {
    for(int j=0;j<5;j++) {
      int x;
      cin >> x;
      bingo_call(x);
      if(bingo_check()>=3) {
        if(answer==-1) answer = cnt;
      }
      cnt+=1;
    }
  }
  cout << answer << '\n';
  return 0;
}
