/*
    change를 구현할때 check배열에 괄호삭제 부분을 false로 설정하고 true부분만 temp에 옮겨 result에 넣는게 더 간단할듯 함.
*/
// #include <bits/stdc++.h>
// using namespace std;
// set<string> result;
// string change(string n,vector<pair<int,int>> vec,vector<int> temp)
// {
//     for(int i=0;i<temp.size();i++)
//     {
//         if(temp[i]==1)
//         {
//             int x = vec[i].first;
//             int y = vec[i].second;
//             n[x] = 'x';
//             n[y] = 'x';
//         }
//     }
//     for(int i=0;i<n.size();i++)
//     {
//         if(n[i]=='x')
//         {
//             n.erase(i,1);
//             i--;
//         }
//     }
//     return n;
// }
// void dfs(vector<pair<int,int>> vec,string n,vector<int> temp)
// {
//     if(temp.size()==vec.size())
//     {
//         string x = change(n,vec,temp);
//         if(n!=x) result.insert(x);
//         return;
//     }
//     temp.push_back(0);
//     dfs(vec,n,temp);
//     temp.pop_back();
//     temp.push_back(1);
//     dfs(vec,n,temp);
//     temp.pop_back();
// }
// int main()
// {
//     string n;
//     cin >> n;
//     stack<char> st;
//     stack<int> st2;
//     vector<pair<int,int>> vec;
//     for(int i=0;i<n.size();i++)
//     {
//         if(!(n[i]=='('||n[i]==')')) continue;
//         if(st.empty()||n[i]==st.top())
//         {
//             st.push(n[i]);
//             st2.push(i);
//         }
//         else
//         {
//             st.pop();
//             int x = st2.top();
//             st2.pop();
//             int y = i;
//             vec.push_back(make_pair(x,y));
//         }
//         if(!st.empty()&&st.top()==')') break;
//     }
//     vector<int> temp;
//     dfs(vec,n,temp);
//     for(auto k:result)
//     {
//         cout << k << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
stack<pair<char,int>> st;
vector<pair<int,int>> result;
set<string> s;
vector<string> answer;

void go(vector<int> temp, string a) {
  if(temp.size()==result.size()) {
    for(int i=0;i<temp.size();i++) {
      if(temp[i]==0) continue;
      int x,y;
      tie(x,y) = result[i];
      a[x] = ' ';
      a[y] = ' ';
    }
    a.erase(remove(a.begin(),a.end(),' '), a.end());
    s.insert(a);
    return;
  }
  temp.push_back(0);
  go(temp,a);
  temp.pop_back();
  temp.push_back(1);
  go(temp,a);
  temp.pop_back();
}

int main(int argc, char const *argv[])
{
  string a;
  cin >> a;
  for(int i=0;i<a.size();i++) {
    if(a[i]!='('&&a[i]!=')') continue;
    if(st.empty()||a[i]=='(') st.push(make_pair(a[i],i));
    else {
      int x = st.top().second;
      int y = i;
      result.push_back(make_pair(x,y));
      st.pop();
    }
  }
  vector<int> temp;
  go(temp,a);
  answer.assign(s.begin(),s.end());
  answer.erase(find(answer.begin(),answer.end(),a));
  sort(answer.begin(),answer.end());
  for(int i=0;i<answer.size();i++) {
    cout << answer[i] << '\n';
  }
  return 0;
}
