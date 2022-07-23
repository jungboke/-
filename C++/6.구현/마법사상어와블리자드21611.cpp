// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int dx[] = {-1,1,0,0};
// int dy[] = {0,0,-1,1};
// int dt[] = {2,1,3,0};
// int check[4];
// vector<int> magic(vector<vector<int>> a,int d,int s,int sx,int sy,int cnt)
// {
//     int n = a.size();
//     int nx = sx;
//     int ny = sy;
//     for(int j=0;j<s;j++)
//     {
//         nx += dx[d];
//         ny += dy[d];
//         if(a[nx][ny]==0) continue;
//         a[nx][ny] = 0;
//         cnt--;
//     }
//     vector<int> result;
//     int idx = 0;
//     int t = 1;
//     d = 0;
//     nx=sx;
//     ny=sy;
//     while(idx!=cnt)
//     {
//         for(int m=0;m<2;m++)
//         {
//             for(int i=0;i<t;i++)
//             {
//                 nx = nx+dx[dt[d]];
//                 ny = ny+dy[dt[d]];
//                 if(a[nx][ny]!=0)
//                 {
//                     result.push_back(a[nx][ny]);
//                     idx++;
//                 }
//                 if(idx==cnt) return result;
//             }
//             d = (d+1)%4;
//         }
//         t++;
//     }
//     return result;
// }
// void boom(vector<int> &temp)
// {
//     bool flag = true;
//     while(flag==true)
//     {
//         vector<int> result;
//         if(temp.size()==0) break;
//         flag = false;
//         int cnt = 1;
//         for(int i=0;i<temp.size()-1;i++)
//         {
//             if(temp[i]==temp[i+1])
//             {
//                 cnt++;
//             }
//             else
//             {
//                 if(cnt>=4)
//                 {
//                     check[temp[i]] += cnt;
//                     flag = true;
//                 }
//                 else
//                 {
//                     for(int j=i;j>i-cnt;j--)
//                     {
//                         result.push_back(temp[j]);
//                     }
//                 }
//                 cnt = 1;
//             }
//         }
//         if(cnt>=4)
//         {
//             check[temp[temp.size()-1]] += cnt;
//             flag = true;
//         }
//         else
//         {
//             for(int j=temp.size()-1;j>temp.size()-1-cnt;j--)
//             {
//                 result.push_back(temp[j]);
//             }
//         }
//         temp = result;
//     }
// }
// void change(vector<vector<int>> a,vector<int> &temp)
// {
//     int n = a.size();
//     int cnt = 1;
//     vector<int> result;
//     if(temp.size()==0) return;
//     for(int i=0;i<temp.size()-1;i++)
//     {
//         if(temp[i]==temp[i+1])
//         {
//             cnt++;
//         }
//         else
//         {
//             result.push_back(cnt);
//             result.push_back(temp[i]);
//             cnt = 1;
//         }
//     }
//     result.push_back(cnt);
//     result.push_back(temp[temp.size()-1]);
//     while(result.size()>=n*n)
//     {
//         result.pop_back();
//     }
//     temp = result;
// }
// void changea(vector<vector<int>> &a,vector<int> temp,int sx,int sy)
// { 
//     int n = a.size();
//     vector<vector<int>> tmp_a(n,vector<int>(n,0));
//     if(temp.size()==0)
//     {
//         a = tmp_a;
//         return;
//     }
//     int nx = sx;
//     int ny = sy;
//     int cnt = temp.size();
//     int idx = 0;
//     int t = 1;
//     int d = 0;
//     while(idx!=cnt)
//     {
//         for(int m=0;m<2;m++)
//         {
//             for(int i=0;i<t;i++)
//             {
//                 nx += dx[dt[d]];
//                 ny += dy[dt[d]];
//                 tmp_a[nx][ny] = temp[idx];
//                 idx++;
//                 if(idx==cnt)
//                 {
//                     a = tmp_a;
//                     return;
//                 }
//             }
//             d = (d+1)%4;
//         }
//         t++;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> a(n,vector<int>(n,0));
//     int sx = n/2;
//     int sy = n/2;
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<n;j++)
//         {
//             cin >> a[i][j];
//         }
//     }
//     for(int i=0;i<m;i++)
//     {
//         int d,s;
//         cin >> d >> s;
//         d-=1;
//         int cnt = 0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 if(a[i][j]!=0) cnt++;
//             }
//         }
//         vector<int> temp = magic(a,d,s,sx,sy,cnt);
//         boom(temp);
//         change(a,temp);
//         changea(a,temp,sx,sy);
//     }
//     int answer = 0;
//     answer += 1*check[1];
//     answer += 2*check[2];
//     answer += 3*check[3];
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int ddx[] = {1,0,-1,0};
int ddy[] = {0,1,0,-1};
int a[50][50];
int answer[4];
int N;

void blizard(int d, int s) {
  int x = ((N+1)/2)-1;
  int y = ((N+1)/2)-1;
  for(int i=0;i<s;i++) {
    x += dx[d];
    y += dy[d];
    a[x][y] = 0;
  }
}

vector<int> make_vec() {
  int x = ((N+1)/2) - 1;
  int y = ((N+1)/2) - 1;
  vector<int> temp;
  int cnt = 2;
  while(temp.size()!=pow(N,2)-1) {
    x -= 1;
    y -= 1;
    for(int i=0;i<4;i++) {
      for(int j=0;j<cnt;j++) {
        x += ddx[i];
        y += ddy[i];
        temp.push_back(a[x][y]);
      }
    }
    cnt+=2;
  }
  temp.erase(remove(temp.begin(),temp.end(),0),temp.end());
  return temp;
}

void bomb(vector<int> &temp) {
  bool flag = true;
  while(flag==true) {
    flag = false;
    int cnt = 1;
    for(int i=1;i<temp.size();i++) {
      if(temp[i]==temp[i-1]) cnt+=1;
      else {
        if(cnt>=4) {
          answer[temp[i-1]]+=cnt;
          flag = true;
          for(int j=1;j<=cnt;j++) {
            temp[i-j] = 0;
          }
        }
        cnt = 1;
      }
    }
    if(cnt>=4) {
      answer[temp[temp.size()-1]]+=cnt;
      flag = true;
      int end = temp.size()-1;
      for(int j=1;j<=cnt;j++) {
        temp[end-j] = 0;
      }
    }
    temp.erase(remove(temp.begin(),temp.end(),0),temp.end());
  }
}

void change(vector<int> &temp) {
  vector<int> result;
  int cnt = 1;
  for(int i=1;i<temp.size();i++) {
    if(temp[i]==temp[i-1]) cnt+=1;
    else {
      result.push_back(cnt);
      result.push_back(temp[i-1]);
      cnt = 1;
    }
  }
  result.push_back(cnt);
  result.push_back(temp[temp.size()-1]);
  temp = result;
}

void make_a(vector<int> temp) {
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      a[i][j] = 0;
    }
  }
  int x = ((N+1)/2)-1;
  int y = ((N+1)/2)-1;
  int cnt = 2;
  int idx = 0;
  bool flag=  true;
  while(flag==true) {
    x -= 1;
    y -= 1;
    for(int i=0;i<4;i++) {
      for(int j=0;j<cnt;j++) {
        x += ddx[i];
        y += ddy[i];
        a[x][y] = temp[idx++];
        if(idx>=temp.size()||idx>=pow(N,2)-1) {
          flag = false;
          break;
        } 
      }
      if(flag==false) break;
    }
    cnt+=2;
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> a[i][j];
    }
  }
  for(int i=0;i<m;i++) {
    int d,s;
    cin >> d >> s;
    blizard(d-1,s);
    vector<int> temp;
    temp = make_vec();
    if(temp.empty()) break;
    bomb(temp);
    change(temp);
    make_a(temp);
  }

  cout << answer[1]+2*answer[2]+3*answer[3] << '\n';
  return 0;
}
/*
    달팽이모양으로 도는 배열의 인덱스를 구하는것이 관건임.
    boom부분에서 4개 이상연속인 부분을 0으로 초기화하고 마지막에 0인걸 다없애는 방식으로 했는데
    시간초과발생함.
*/