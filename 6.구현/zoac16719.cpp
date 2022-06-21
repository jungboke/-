/*
    문제의 핵심이 되는 부분은 문자들이 추가될때 앞,중간,뒤 어느 부분에 추가되는지 판별하는 것.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[101];
string change(string a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
        {
            a.erase(a.begin()+i);
            i--;
        } 
    }
    return a;
}
int main()
{
    string a;
    cin >> a;
    string temp = "";
    int size = a.size();
    for(int i=0;i<size;i++)
    {
        temp += '0';
    }
    bool flag = true;
    while(flag==true)
    {
        flag = false;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='0') flag = true;
        }
        string mini = "0";
        int min_idx = 0;
        for(int i=0;i<a.size();i++)
        {
            if(check[i]==true) continue;
            string temp2 = temp;
            temp2[i] = a[i];
            temp2 = change(temp2);
            if(mini=="0"||mini>temp2)
            {
                mini = temp2;
                min_idx = i;
            }
        }
        temp[min_idx] = a[min_idx];
        check[min_idx] = true;
        if(flag==true) cout << change(temp) << '\n';
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool check[101];
// int main()
// {
//     string a;
//     cin >> a;
//     while(true)
//     {
//         string mini = "";
//         int min_idx = 0;
//         bool flag = true;
//         for(int i=0;i<a.size();i++)
//         {
//             if(check[i]==true) continue;
//             check[i] = true;
//             flag = false;
//             string temp = "";
//             for(int j=0;j<a.size();j++)
//             {
//                 if(check[j]==true)
//                 {
//                     temp += a[j];
//                 }
//             }
//             check[i] = false;
//             if(mini==""||temp<mini)
//             {
//                 mini = temp;
//                 min_idx = i;
//             }
//         }
//         if(flag==true) break;
//         check[min_idx] = true;
//         string answer = "";
//         for(int i=0;i<a.size();i++)
//         {
//             if(check[i]==true) answer += a[i];
//         }
//         cout << answer << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
bool check[101];

int main(int argc, char const *argv[])
{
  string x;
  cin >> x;
  bool flag = true;
  while(flag==true) {
    flag = false;
    string mini = "";
    int min_idx = 0;
    for(int i=0;i<x.size();i++) {
      if(check[i]==false) {
        flag = true;
        check[i] = true;
        string temp = "";
        for(int j=0;j<x.size();j++) {
          if(check[j]==true) temp += x[j];
        }
        if(mini==""||mini>temp) {
          mini = temp;
          min_idx = i;
        }
        check[i] = false;
      }
    }
    if(flag==false) break;
    check[min_idx] = true;
    string answer = "";
    for(int i=0;i<x.size();i++) {
      if(check[i]==true) answer += x[i];
    }
    cout << answer << '\n';
  }
  return 0;
}
