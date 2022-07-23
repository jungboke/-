/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a;
        cin >> a;
        if(a=="end") break;
        int m_cnt = 0;
        int j_cnt = 0;
        char now = a[0]+1;
        bool flag = true;
        bool flag2 = false;
        for(int i=0;i<a.size();i++)
        {
            if(now==a[i]&&a[i]!='e'&&a[i]!='o')
            {
                flag = false;
                break;
            }
            now = a[i]; 
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            {
                flag2 = true;
                j_cnt = 0;
                m_cnt++;
            }
            else if(isalpha(a[i])!=0)
            {
                m_cnt = 0;
                j_cnt++;
            }
            
            if(j_cnt>=3||m_cnt>=3)
            {
                flag = false;
                break;
            }
        }
        if(flag2==false) flag = false;
        if(flag==true) cout << '<' << a << '>' << " is acceptable." << '\n';
        else cout << '<' << a << '>' << " is not acceptable." << '\n';  
    }

    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a;
        cin >> a;
        if(a=="end") break;
        int m_cnt = 0;
        int j_cnt = 0;
        bool flag = true;
        bool mflag = false;
        char bword = a[0]-1;
        for(int i=0;i<a.size();i++)
        {
            if(bword==a[i]&&a[i]!='e'&&a[i]!='o')
            {
                flag = false;
                break;
            }
            bword = a[i];
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            {
                mflag = true;
                j_cnt = 0;
                m_cnt++;
            }
            else
            {
                m_cnt = 0;
                j_cnt++;
            }
            if(m_cnt>=3||j_cnt>=3)
            {
                flag = false;
                break;
            }
        }
        if(mflag==false) flag = false;
        if(flag==true) cout << '<' << a << '>' << " is acceptable." << '\n';
        else cout << '<' << a << '>' << " is not acceptable." << '\n';
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// bool test(string a)
// {
//     bool flag = true;
//     bool flag2 = false;
//     int mo = 0;
//     int ja = 0;
//     char last = a[0] - 1;
//     for(int i=0;i<a.size();i++)
//     {
//         if(last==a[i]&&a[i]!='e'&&a[i]!='o')
//         {
//             flag = false;
//             break;
//         }
//         last = a[i];
//         if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
//         {
//             flag2 = true;
//             mo += 1;
//             ja = 0;
//         }
//         else
//         {
//             ja += 1;
//             mo = 0;
//         }
//         if(mo==3||ja==3)
//         {
//             flag = false;
//             break;
//         }
//     }
//     if(flag==true&&flag2==true) return true;
//     else return false;
// }
// int main()
// {
//     while(true)
//     {
//         string a;
//         cin >> a;
//         if(a=="end") break;
//         if(test(a)==true) cout << '<' << a << '>' << " is acceptable." << '\n';
//         else cout << '<' << a << '>' << " is not acceptable." << '\n'; 
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<char> alp = {'a','e','i','o','u'};

bool str_check(string a) {
  bool flag1 = false;
  bool flag2 = true;
  bool flag3 = true;
  for(int i=0;i<a.size();i++) {
    if(find(alp.begin(),alp.end(),a[i])!=alp.end()) {
      flag1 = true;
      break;
    }
  }
  int mo = 0;
  int ja = 0;
  for(int i=0;i<a.size();i++) {
    if(find(alp.begin(),alp.end(),a[i])!=alp.end()) {
      mo+=1;
      ja=0;
    } else {
      ja+=1;
      mo=0;
    }
    if(mo==3||ja==3) {
      flag2 = false;
      break;
    }
  }
  for(int i=1;i<a.size();i++) {
    if(a[i-1]==a[i]&&a[i]!='e'&&a[i]!='o') {
      flag3 = false;
      break;
    }
  }

  if(flag1==true&&flag2==true&&flag3==true) return true;
  else return false;
}

int main(int argc, char const *argv[])
{
  while(true) {
    string a;
    cin >> a;
    if(a=="end") break;
    if(!str_check(a)) {
      cout << '<' << a << '>' << " is not acceptable." << '\n';
    }
    else {
      cout << '<' << a << '>' << " is acceptable." << '\n';
    }
  }

  return 0;
}





















