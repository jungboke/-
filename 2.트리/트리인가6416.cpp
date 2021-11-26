/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <string.h>
using namespace std;
vector<int> a[1000];
bool check[1000];
void dfs(int num)
{
    check[num] = true;
    for(auto k:a[num])
    {
        if(check[k]==false)
        {
            dfs(k);
        }
    }
}
int main()
{
    int idx = 1;
    while(true)
    {
        memset(check,false,sizeof(check));
        bool Finalflag = true;
        set<int> Node;
        set<int> target;
        bool flag = true;
        int cnt = 0;
        while(true)
        {
            int x,y;
            cin >> x >> y;
            if(x==0&&y==0) break;
            else if(x<0&&y<0)
            {
                flag = false;
                break;
            }
            a[x].push_back(y);
            target.insert(y);
            Node.insert(x); Node.insert(y);
            cnt++;
        }
        vector<int> Node2;
        Node2.assign(Node.begin(),Node.end());
        int root = -1;
        int root_cnt = 0;
        for(int i=0;i<Node2.size();i++)
        {
            if(find(target.begin(),target.end(),Node2[i])==target.end())
            {
                root = Node2[i];
                root_cnt++;
            }
        }
        if(root==-1||root_cnt>1) Finalflag = false;
        if(flag==false) break;
        if(cnt!=target.size()) Finalflag = false;
        dfs(root);
        for(int i=0;i<Node2.size();i++)
        {
            if(check[Node2[i]]==false) Finalflag = false;
        }
        if(Node.empty()) Finalflag = true;
        if(Finalflag==true) cout << "Case " << idx << " is a tree." << '\n';
        else cout << "Case " << idx << " is not a tree." << '\n';
        
        for(int i=0;i<Node2.size();i++)
        {
            a[Node2[i]].clear();
        }
        idx++;
    }
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> a[1000];
int ind[1000];
bool check[1000];
void dfs(int root)
{
    check[root] = true;
    for(auto k:a[root])
    {
        if(check[k]==false) dfs(k);
    }
}

int main()
{
    int cnt = 1;
    while(true)
    {
        for(int i=0;i<1000;i++)
        {
            a[i].clear();
        }
        memset(ind,0,sizeof(ind));
        memset(check,false,sizeof(check));
        bool flag = true;
        set<int> s;
        while(true)
        {
            int x,y;
            cin >> x >> y;
            if(x<0&&y<0) return 0;
            else if(x==0&&y==0) break;
            s.insert(x);
            s.insert(y);
            a[x].push_back(y);
            ind[y]++;
        }
        int root = -1;
        int nroot = 0;
        for(auto k:s)
        {
            if(ind[k]==0) root = k;
            else if(ind[k]==1) nroot++;
        }
        if(root==-1||nroot!=s.size()-1) flag = false;
        dfs(root);
        for(auto k:s)
        {
            if(check[k]==false) flag = false;
        }
        if(s.size()==0) flag = true;
        if(flag==false) cout << "Case " << cnt << " is not a tree." << '\n';
        else cout << "Case " << cnt << " is a tree." << '\n';
        cnt++; 
    }
    return 0;
}