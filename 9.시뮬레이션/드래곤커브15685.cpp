/*
    dragon curve가 만들어지는 규칙을 알아내기만하면 간단히 풀수 있음.
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int dx[] = {0,-1,0,1};
// int dy[] = {1,0,-1,0};
// int a[101][101];
// vector<int> curve(int w,int cnt)
// {
//     vector<int> temp;
//     temp.push_back(w);
//     for(int i=0;i<cnt;i++)
//     {
//         for(int j=temp.size()-1;j>=0;j--)
//         {
//             temp.push_back((temp[j]+1)%4);
//         }
//     }
//     return temp;    
// }
// void make(int x,int y,vector<int> temp)
// {
//     a[x][y] = 1;
//     for(int i=0;i<temp.size();i++)
//     {
//         int w = temp[i];
//         x = x+dx[w];
//         y = y+dy[w];
//         a[x][y] = 1;
//     }
// }
// int count()
// {
//     int cnt = 0;
//     for(int i=0;i<101;i++)
//     {
//         for(int j=0;j<101;j++)
//         {
//             if(i+1<101&&j+1<101)
//             {
//                 if(a[i][j]==1&&a[i+1][j]==1&&a[i][j+1]==1&&a[i+1][j+1]==1)
//                     cnt++;
//             }
//         }
//     }
//     return cnt;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++)
//     {
//         int x,y,w,cnt;
//         cin >> x >> y >> w >> cnt;
//         vector<int> temp;
//         temp = curve(w,cnt);
//         make(y,x,temp);
//     }
//     cout << count() << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
int a[101][101];

vector<int> curve(int d, int g) {
  vector<int> result = {d};
  while(g--) {
    vector<int> temp = result;
    reverse(temp.begin(),temp.end());
    for(int i=0;i<temp.size();i++) {
      temp[i] = (temp[i]+1)%4;
    }
    result.insert(result.end(),temp.begin(),temp.end());
  }
  return result;
}

void move(int x, int y, vector<int> temp) {
  a[x][y] = 1;
  for(int i=0;i<temp.size();i++) {
    x+=dx[temp[i]];
    y+=dy[temp[i]];
    a[x][y] = 1;
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x,y,d,g;
    cin >> x >> y >> d >> g;
    vector<int> temp = curve(d,g);
    move(y,x,temp);
  }
  int answer = 0;
  for(int i=0;i<100;i++) {
    for(int j=0;j<100;j++) {
      if(a[i][j]==1&&a[i+1][j]==1) {
        if(a[i][j+1]==1&&a[i+1][j+1]==1) answer+=1;
      }
    }
  }
  cout << answer << '\n';
  return 0;
}