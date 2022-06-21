/*
    문제의 핵심은 가장 긴 감소하는 숫자가 9876543210 이라는 것을 파악하는 일임.
    temp 벡터의 사이즈가 10을 넘어가면 감소하는 숫자가 존재할수 없으므로 재귀함수의 break로 설정함.
    모든 감소하는 숫자를 구한후 sorting해서 답을 구함. 실패한 이유는 0 1 10 2 순으로
    측정하여 sorting이 되지 않았음.
*/
/*
    dfs 구현문 중 끝나는 부분을 정하는 첫 if문을 맨 마지막으로 보낼 수 있음.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long> result;
long long change(vector<int> temp)
{
    long long num = 0;
    for(int i=0;i<temp.size();i++)
    {
        num = num*10+temp[i];
    }
    return num;
}
void dfs(vector<int> temp,int idx)
{
    if(temp.size()==10)
    {
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(idx==-1||temp[idx]>i)
        { 
            temp.push_back(i);
            result.push_back(change(temp));
            dfs(temp,idx+1);
            temp.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> temp;
    dfs(temp,-1);
    sort(result.begin(),result.end());
    if(n>result.size()) cout << -1 << '\n';
    else cout << result[n-1] << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// bool check[10];
// vector<long long> result;
// void dfs(string a,int prev)
// {
//     bool flag = true;
//     result.push_back(stoll(a));
//     for(int i=0;i<=9;i++)
//     {
//         if(check[i]==true||prev<=i) continue;
//         flag = false;
//         check[i] = true;
//         dfs(a+to_string(i),i);
//         check[i] = false;
//     }
//     if(flag==true)
//     {
//         return;
//     }
// } 

// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0;i<=9;i++)
//     {
//         string temp = to_string(i);
//         check[i] = true;
//         dfs(temp,i);
//         check[i] = false;
//     }
//     sort(result.begin(),result.end());
//     if(n-1>=result.size()) cout << -1 << '\n';
//     else cout << result[n-1] << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<long long> result;

void dfs(string temp, int prev) {
  for(int i=0;i<=9;i++) {
    if(i>=prev) continue;
    temp += to_string(i);
    dfs(temp,i);
    temp.erase(temp.size()-1,1);
  }
  result.push_back(stoll(temp));
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<=9;i++) {
    string temp = to_string(i);
    dfs(temp,i);
  }
  sort(result.begin(),result.end());
  if(n>result.size()) cout << -1 << '\n';
  else cout << result[n-1] << '\n';
  return 0;
}