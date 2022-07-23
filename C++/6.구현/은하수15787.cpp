// #include <vector>
// #include <algorithm>
// #include <iostream>
// #include <set>
// using namespace std;
// void moveback(vector<int> &a)
// {
//     vector<int> tmp_a = a;
//     tmp_a[0] = 0;
//     for(int i=0;i<a.size()-1;i++)
//     {
//         tmp_a[i+1] = a[i];
//     }
//     a = tmp_a;
// }
// void movefront(vector<int> &a)
// {
//     vector<int> tmp_a = a;
//     tmp_a[a.size()-1] = 0;
//     for(int i=a.size()-1;i>0;i--)
//     {
//         tmp_a[i-1] = a[i];
//     }
//     a = tmp_a;
// }
// int main()
// {
//     int n,m;
//     cin >> n >> m;
//     vector<vector<int>> train(n,vector<int>(20,0));
//     while(true)
//     {
//         int x;
//         cin >> x;
//         if(cin.eof()) break;
//         if(x==1)
//         {
//             int a,b;
//             cin >> a >> b;
//             train[a-1][b-1] = 1;
//         }
//         else if(x==2)
//         {
//             int a,b;
//             cin >> a >> b;
//             train[a-1][b-1] = 0;
//         }
//         else if(x==3)
//         {
//             int a;
//             cin >> a;
//             moveback(train[a-1]);
//         }
//         else if(x==4)
//         {
//             int a;
//             cin >> a;
//             movefront(train[a-1]);
//         }
//     }
//     set<string> result;
//     for(int i=0;i<train.size();i++)
//     {
//         string temp = "";
//         for(int j=0;j<train[i].size();j++)
//         {
//             temp += to_string(train[i][j]);
//         }
//         result.insert(temp);
//     }
//     cout << result.size() << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
int a[100001][21];
set<string> result;

void move_back(int x) {
  for(int j=19;j>0;j--) {
    a[x][j] = a[x][j-1];
  }
  a[x][0] = 0;
}

void move_front(int x) {
  for(int j=0;j<19;j++) {
    a[x][j] = a[x][j+1];
  }
  a[x][19] = 0;
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  for(int i=0;i<m;i++) {
    int x;
    cin >> x;
    if(x==1) {
      int y,z;
      cin >> y >> z;
      a[y-1][z-1] = 1;
    } else if(x==2) {
      int y,z;
      cin >> y >> z;
      a[y-1][z-1] = 0;
    } else if(x==3) {
      int y;
      cin >> y;
      move_back(y-1);
    } else {
      int y;
      cin >> y;
      move_front(y-1);
    }
  }
  for(int i=0;i<n;i++) {
    string temp = "";
    for(int j=0;j<20;j++) {
      temp += to_string(a[i][j]);
    }
    result.insert(temp);
  }
  cout << result.size() << '\n';
  return 0;
}
