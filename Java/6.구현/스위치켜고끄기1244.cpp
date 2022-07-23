/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void man(vector<int> &a,int num)
{
    for(int i=0;i<a.size();i++)
    {
        if((i+1)%num==0)
        {
            a[i] = 1-a[i];
        }
    }
}
void woman(vector<int> &a,int num)
{
    a[num-1] = 1-a[num-1];
    for(int i=1;i<=num-1;i++)
    {
        if(a[num-1-i]==a[num-1+i]&&num-1-i>=0&&num-1+i<a.size())
        {
            a[num-1-i] = 1-a[num-1-i];
            a[num-1+i] = 1-a[num-1+i];
        }
        else break;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<pair<int,int>> student(m);
    for(int i=0;i<m;i++)
    {
        cin >> student[i].first;
        cin >> student[i].second;
    }
    for(int i=0;i<student.size();i++)
    {
        if(student[i].first==1) man(a,student[i].second);
        else if(student[i].first==2) woman(a,student[i].second);
    }
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << ' ';
        if((i+1)%20==0) cout << '\n';
    }
    return 0;
}*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// void man(vector<int> &a,int num)
// {
//     for(int i=0;i<a.size();i++)
//     {
//         if((i+1)%num==0) a[i] = 1 - a[i];
//     }
// }
// void woman(vector<int> &a,int num)
// {
//     num -= 1;
//     a[num] = 1-a[num];
//     for(int i=1;i<=num;i++)
//     {
//         if(num+i>=a.size()) break;
//         if(a[num-i] == a[num+i])
//         {
//             a[num-i] = 1-a[num-i];
//             a[num+i] = 1-a[num+i];
//         }
//         else break;
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     int m;
//     cin >> m;
//     for(int i=0;i<m;i++)
//     {
//         int x,y; // x 성별 y 받은수
//         cin >> x >> y;
//         if(x==1) man(a,y);
//         else woman(a,y);
//     }
//     for(int i=0;i<n;i++)
//     {
//         cout << a[i] << ' ';
//         if((i+1)%20==0) cout << '\n';
//     }
//     cout << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int N;

void man(int x) {
  for(int i=0;i<N;i++) {
    if((i+1)%x==0) {
      a[i] = 1-a[i];
    }
  }
}

void woman(int x) {
  x-=1;
  int idx = 1;
  a[x] = 1-a[x];
  while(x-idx>=0&&x+idx<N) {
    if(a[x-idx]==a[x+idx]) {
      a[x-idx] = 1-a[x-idx];
      a[x+idx] = 1-a[x+idx];
    }
    else break;
    idx+=1;
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int m;
  cin >> m;
  for(int i=0;i<m;i++) {
    int x,y;
    cin >> x >> y;
    if(x==1) man(y);
    else woman(y);
  }
  for(int i=0;i<n;i++) {
    cout << a[i] << ' ';
    if((i+1)%20==0) cout << '\n';
  }
  return 0;
}
