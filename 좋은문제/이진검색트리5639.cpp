/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *left = NULL;
    Node *right = NULL;
};
void addNode(Node *a,Node *b)
{
    if(a->num>b->num)
    {
        if(a->left==NULL)
        {
            a->left = b;
        }
        else addNode(a->left,b);
    }
    else
    {
        if(a->right==NULL)
        {
            a->right = b;
        }
        else addNode(a->right,b);
    }
}
void postorder(Node *root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->num << '\n';
}
int main()
{
    int n;
    vector<Node> a;
    while(cin>>n)
    {
        if(n==EOF) break;
        Node temp;
        temp.num = n;
        a.push_back(temp);
    }
    Node *root;
    root = &a[0];
    for(int i=1;i<a.size();i++)
    {
        addNode(root,&a[i]);
    }
    postorder(root);
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *left = NULL;
    Node *right = NULL;
};
void addNode(Node *root,Node *next)
{
    if(next->num<root->num)
    {
        if(root->left==NULL)
        {
            root->left = next;
        }
        else addNode(root->left,next);
    }
    else if(next->num>root->num)
    {
        if(root->right==NULL)
        {
            root->right = next;
        }
        else addNode(root->right,next);
    }
}
void postorder(Node *root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->num << '\n';
}
int main()
{
    vector<Node> a;
    while(true)
    {
        int n;
        cin >> n;
        if(cin.eof()) break;
        Node temp;
        temp.num = n;
        a.push_back(temp);
    }
    Node *root = &a[0];
    for(int i=1;i<a.size();i++)
    {
        addNode(root,&a[i]);
    }
    postorder(root);
    return 0;
}






















