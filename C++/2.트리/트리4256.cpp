// 전위.중위를 사용하여 트리의 구조를 알수 있는 문제.
/*
    전위,중위순회의 특성을 이용해서 재귀방식으로 postorder구현가능함.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> preorder;
vector<int> inorder;
void go(int root,int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]==preorder[root])
        {
            go(root+1,start,i-1);
            go(root+i-start+1,i+1,end);
            cout << preorder[root] << ' ';
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        preorder.clear();
        inorder.clear();
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            preorder.push_back(x);
        }
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            inorder.push_back(x);
        }
        go(0,0,n-1);
        cout << '\n';
    }
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;
// int preorder[1001];
// int inorder[1001];
// void go(int root,int s,int e)
// {
//     for(int i=s;i<=e;i++)
//     {
//         if(inorder[i]==preorder[root])
//         {
//             go(root+1,s,i-1);
//             go(root+i-s+1,i+1,e);
//             cout << preorder[root] << ' ';
//         }
//     }
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while(t--)
//     {
//         int n;
//         cin >> n;
//         for(int i=0;i<n;i++)
//         {
//             int x;
//             cin >> x;
//             preorder[i] = x;
//         }
//         for(int i=0;i<n;i++)
//         {
//             int x;
//             cin >> x;
//             inorder[i] = x;
//         }
//         go(0,0,n-1);
//         cout << '\n';
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> preorder;
vector<int> inorder;

void go(int root, int s, int e) {
  for(int i=s;i<=e;i++) {
    if(inorder[i]==preorder[root]) {
      go(root+1,s,i-1);
      go(root+i-s+1,i+1,e);
      cout << preorder[root] << ' ';
    }
  }
}

int main(int argc, char const *argv[])
{
  int t;
  cin >> t;
  while(t--) {
    preorder.clear();
    inorder.clear();
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      preorder.push_back(x);
    }
    for(int i=0;i<n;i++) {
      int x;
      cin >> x;
      inorder.push_back(x);
    }
    go(0,0,n-1);
    cout << '\n';
  }
  return 0;
}
