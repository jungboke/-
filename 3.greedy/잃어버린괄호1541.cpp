// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     string a;
//     cin >> a;
//     vector<int> num;
//     vector<char> op;
//     int temp = 0;
//     for(int i=0;i<a.size();i++)
//     {
//         if(isdigit(a[i])!=0) temp = temp*10 + (a[i]-48);
//         else
//         {
//             num.push_back(temp);
//             op.push_back(a[i]);
//             temp = 0;
//         }
//     }
//     num.push_back(temp);
//     int answer = num[0];
//     bool flag = true;
//     temp = 0;
//     for(int i=0;i<op.size();i++)
//     {
//         if(flag==true&&op[i]=='-')
//         {
//             flag = false;
//             temp = num[i+1];
//         }
//         else if(flag==false&&op[i]=='-')
//         {
//             answer -= temp;
//             temp = num[i+1];
//         }
//         else if(flag==false&&op[i]=='+')
//         {
//             temp += num[i+1];
//         }
//         else if(flag==true&&op[i]=='+')
//         {
//             answer += num[i+1];
//         }
//     }
//     answer -= temp;
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> num;
vector<char> op;

void parsing(string a) {
  string temp = "";
  for(int i=0;i<a.size();i++) {
    if(isdigit(a[i])!=0) {
      temp += a[i];
    } else {
      num.push_back(stoi(temp));
      op.push_back(a[i]);
      temp = "";
    }
  }
  num.push_back(stoi(temp));
}

int main(int argc, char const *argv[])
{
  string a;
  cin >> a;
  parsing(a);
  int answer = num[0];
  int temp = 0;
  bool flag = false;
  for(int i=0;i<op.size();i++) {
    if(op[i]=='-') {
      flag = true;
      answer -= temp;
      temp = num[i+1];
    } else {
      if(flag==true) temp += num[i+1];
      else answer += num[i+1];
    }
  }
  answer -= temp;
  cout << answer << '\n';
  return 0;
}
