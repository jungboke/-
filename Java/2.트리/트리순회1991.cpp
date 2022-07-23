// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;
// struct Node
// {
//     char alp;
//     char left;
//     char right;
// };
// Node a[30];
// void preorder(char node,vector<char> &answer)
// {
//     if(node=='0')
//     {
//         return;
//     }
//     answer.push_back(a[node-'A'].alp);
//     preorder(a[node-'A'].left,answer);
//     preorder(a[node-'A'].right,answer);
// }
// void inorder(char node,vector<char> &answer)
// {
//     if(node=='0')
//     {
//         return;
//     }
//     inorder(a[node-'A'].left,answer);
//     answer.push_back(a[node-'A'].alp);
//     inorder(a[node-'A'].right,answer);
// }
// void postorder(char node,vector<char> &answer)
// {
//     if(node=='0')
//     {
//         return;
//     }
//     postorder(a[node-'A'].left,answer);
//     postorder(a[node-'A'].right,answer);
//     answer.push_back(a[node-'A'].alp);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     for(int i=0;i<n;i++)
//     {
//         Node temp;
//         char x,y,z;
//         cin >> x >> y >> z;
//         temp.alp = x;
//         if(y=='.') temp.left = '0';
//         else temp.left = y;
//         if(z=='.') temp.right = '0';
//         else temp.right = z;
//         a[x-'A'] = temp;  
//     }
//     vector<char> answer[3];
//     preorder('A',answer[0]);
//     inorder('A',answer[1]);
//     postorder('A',answer[2]);
//     for(int i=0;i<3;i++)
//     {
//         for(int j=0;j<answer[i].size();j++)
//         {
//             cout << answer[i][j];
//         }
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
struct Node {
  char left = NULL;
  char right = NULL;
};
Node a[30];

void preorder(char root, vector<char> &answer) {
  if(root==NULL) return;
  answer.push_back(root);
  preorder(a[root-'A'].left,answer);
  preorder(a[root-'A'].right,answer);
}

void inorder(char root, vector<char> &answer) {
  if(root==NULL) return;
  inorder(a[root-'A'].left,answer);
  answer.push_back(root);
  inorder(a[root-'A'].right,answer);
}

void postorder(char root, vector<char> &answer) {
  if(root==NULL) return;
  postorder(a[root-'A'].left,answer);
  postorder(a[root-'A'].right,answer);
  answer.push_back(root);
}

int main()
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    char x,y,z;
    cin >> x >> y >> z;
    Node temp;
    if(y!='.') temp.left = y;
    if(z!='.') temp.right = z;
    a[x-'A'] = temp;
  }
  vector<char> answer[3];
  preorder('A',answer[0]);
  inorder('A',answer[1]);
  postorder('A',answer[2]);
  for(int i=0;i<3;i++) {
    for(int j=0;j<answer[i].size();j++) {
      cout << answer[i][j];
    }
    cout << '\n';
  }
  return 0;
}