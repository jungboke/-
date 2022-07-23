// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> ans;
// void go(vector<int> words, int alp, int index, int count){
//     if(count==0){
//         int temp = 0;
//         for(int word : words){
//             if((word&((1<<26)-1-alp))==0) temp++; 
//         }
//         ans.push_back(temp);
//         return;
//     }
//     if(index==26) return;
//     go(words,alp|(1<<index),index+1,count-1);
//     if(index!='a'-'a'&&index!='n'-'a'&&index!='t'-'a'&&index!='i'-'a'&&index!='c'-'a'){
//         go(words,alp,index+1,count);
//     }
// }



// int main() {

//     int n, k;
//     cin >> n >> k;
//     vector<int> words(n);
//     for(int i=0;i<n;i++){
//         string s;
//         cin >> s;
//         for(char c : s){
//             int a = c - 'a';
//             words[i] = words[i] | (1<<a);    
//         }
//     }
//     go(words,0,0,k);
//     cout << *max_element(ans.begin(),ans.end()) << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<char> none = {'a','n','t','i','c'};
int maxi = -1;

int word_check(vector<char> temp) {
  int cnt = 0;
  int num = 0;
  for(int i=0;i<none.size();i++) {
    int idx = none[i]-'a';
    num = num | (1<<idx);
  }
  for(int i=0;i<temp.size();i++) {
    int idx = temp[i]-'a';
    num = num | (1<<idx);
  }
  for(int i=0;i<a.size();i++) {
    if((a[i]&num)==a[i]) cnt+=1; 
  }
  return cnt;
}

void dfs(vector<char> temp, int start, int m) {
  if(temp.size()==m) {
    int x = word_check(temp);
    maxi = max(maxi,x);
    return;
  }
  for(int i=start;i<26;i++) {
    char alp = 'a'+i;
    if(find(none.begin(),none.end(),alp)!=none.end()) continue;
    temp.push_back(alp);
    dfs(temp,i+1,m);
    temp.pop_back(); 
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  if(m<5) {
    cout << 0 << '\n';
    return 0;
  }
  for(int i=0;i<n;i++) {
    string x;
    cin >> x;
    int num = 0;
    for(int j=0;j<x.size();j++) {
      int idx = x[j]-'a';
      num = num | (1<<idx);
    }
    a.push_back(num);
  }
  vector<char> temp;
  dfs(temp,0,m-5);
  cout << maxi << '\n';
  return 0;
}
