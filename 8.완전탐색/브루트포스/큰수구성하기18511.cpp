/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> result;
void dfs(vector<int> a,int cnt,string s,int sum)
{
    if(cnt==s.size())
    {
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(sum*10+a[i]<=stoi(s))
            result.push_back(sum*10+a[i]);
        dfs(a,cnt+1,s,sum*10+a[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    string str_n = to_string(n);
    int k;
    cin >> k;
    vector<int> a;
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    dfs(a,0,str_n,0);
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int maxi = 0;
void go(vector<int> a,vector<int> temp,int target,int max)
{
    if(temp.size()>max)
    {
        return;
    }
    int num = 0;
    for(int i=0;i<temp.size();i++)
    {
        num = num*10 + temp[i];
    }
    if(num<=target)
    {
        if(maxi<num) maxi = num;
    }
    for(int i=0;i<a.size();i++)
    {
        temp.push_back(a[i]);
        go(a,temp,target,max);
        temp.pop_back();
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    string str_n = to_string(n);
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    vector<int> temp;
    go(a,temp,n,str_n.size());
    cout << maxi << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int maxi = 0;
// void go(vector<int> a,string target,int length,string num)
// {
//     if(num.size()==length+1)
//     {
//         return;
//     }
//     if(num!=""&&stoi(num)<=stoi(target))
//     {
//         if(stoi(num)>maxi)
//         {
//             maxi = stoi(num);
//         }
//     }
//     for(int i=0;i<a.size();i++)
//     {
//         num += to_string(a[i]);
//         go(a,target,length,num);
//         num.erase(num.end()-1);
//     }
// }
// int main()
// {
//     string str_a;
//     cin >> str_a;
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     go(a,str_a,str_a.size(),"");
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<char> a;
vector<int> answer;

void go(int length, string sum, int target) {
  if(sum.size()==length+1) {
    return;
  }
  if(sum!=""&&stoi(sum)<=target) answer.push_back(stoi(sum));
  for(int i=0;i<a.size();i++) {
    go(length,sum+a[i],target);
  }
}

int main(int argc, char const *argv[])
{
  int n,k;
  cin >> n >> k;
  for(int i=0;i<k;i++) {
    char x;
    cin >> x;
    a.push_back(x);
  }
  go(to_string(n).size(),"",n);
  
  cout << *max_element(answer.begin(),answer.end()) << '\n';
  return 0;
}






















