/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
pair<int,int> check(char alp,vector<string> a)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j] == alp)
            {
                return make_pair(i,j);
            }
        }
    }
    return make_pair(0,0);
}
int main()
{
    vector<string> a;
    string temp = "";
    temp = "qwertyuiop";
    a.push_back(temp);
    temp = "asdfghjkl";
    a.push_back(temp);
    temp = "zxcvbnm";
    a.push_back(temp);
    char l,r;
    cin >> l >> r;
    cin >> temp;
    int sum = 0;
    for(int i=0;i<temp.size();i++)
    {
        int x,y;
        tie(x,y) = check(temp[i],a);
        if(y<=4&&temp[i]!='b')
        {
            int lx,ly;
            tie(lx,ly) = check(l,a);
            sum += abs(lx-x) + abs(ly-y) + 1;
            l = temp[i];
        }
        else if(y>4||temp[i]=='b')
        {
            int rx,ry;
            tie(rx,ry) = check(r,a);
            sum += abs(rx-x) + abs(ry-y) + 1;
            r = temp[i];
        }
    }
    cout << sum << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <tuple>
// #include <cmath>
// using namespace std;
// pair<int,int> find(char x,vector<string> a)
// {
//     for(int i=0;i<a.size();i++)
//     {
//         for(int j=0;j<a[i].size();j++)
//         {
//             if(a[i][j] == x)
//             {
//                 return (make_pair(i,j));
//             }
//         }
//     }
// }
// int main()
// {
//     vector<string> a;
//     a.push_back("qwertyuiop");
//     a.push_back("asdfghjkl");
//     a.push_back("zxcvbnm");
//     int lx,ly,rx,ry;
//     char x,y;
//     cin >> x >> y;
//     tie(lx,ly) = find(x,a);
//     tie(rx,ry) = find(y,a);
//     string b;
//     cin >> b;
//     int length = 0;
//     for(int i=0;i<b.size();i++)
//     {
//         char k = b[i];
//         int x,y;
//         tie(x,y) = find(k,a);
//         if(y>=5)
//         {
//            length += abs(rx-x) + abs(ry-y) + 1;
//            rx = x; ry = y; 
//         }
//         else
//         {
//             if(k=='b')
//             {
//                 length += abs(rx-x) + abs(ry-y) + 1;
//                 rx = x; ry = y;
//             }
//             else
//             {
//                 length += abs(lx-x) + abs(ly-y) + 1;
//                 lx = x; ly = y;
//             }
//         }
//     }
//     cout << length << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<string> key;

pair<int,int> word_find(char x) {
  int nx,ny;
  for(int i=0;i<key.size();i++) {
    for(int j=0;j<key[i].size();j++) {
      if(key[i][j]==x) {
        nx = i;
        ny = j;
      }
    }
  }
  return make_pair(nx,ny);
}

int main(int argc, char const *argv[])
{
  key.push_back("qwertyuiop");
  key.push_back("asdfghjkl");
  key.push_back("zxcvbnm");
  char x,y;
  cin >> x >> y;
  string a;
  cin >> a;
  int lx,ly,rx,ry;
  for(int i=0;i<key.size();i++) {
    for(int j=0;j<key[i].size();j++) {
      if(key[i][j]==x) {
        lx = i;
        ly = j;
      } else if(key[i][j]==y) {
        rx = i;
        ry = j;
      }
    }
  }
  int cnt = 0;
  for(int i=0;i<a.size();i++) {
    cnt+=1;
    int x,y;
    tie(x,y) = word_find(a[i]);
    if(y<=4&&key[x][y]!='b') {
      cnt += abs(lx-x) + abs(ly-y);
      lx = x;
      ly = y;
    } else {
      cnt += abs(rx-x) + abs(ry-y);
      rx = x;
      ry = y;
    }
  }
  cout << cnt << '\n';
  return 0;
}