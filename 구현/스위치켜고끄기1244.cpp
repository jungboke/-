#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void man(vector<int> &a,int num)
{
    for(int i=0;i<a.size();i++)
    {
        if((i+1)%num==0)
        {
            a[i] = 1-a[i];
        }
    }
}
void woman(vector<int> &a,int num)
{
    a[num-1] = 1-a[num-1];
    for(int i=1;i<=num-1;i++)
    {
        if(a[num-1-i]==a[num-1+i]&&num-1-i>=0&&num-1+i<a.size())
        {
            a[num-1-i] = 1-a[num-1-i];
            a[num-1+i] = 1-a[num-1+i];
        }
        else break;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<pair<int,int>> student(m);
    for(int i=0;i<m;i++)
    {
        cin >> student[i].first;
        cin >> student[i].second;
    }
    for(int i=0;i<student.size();i++)
    {
        if(student[i].first==1) man(a,student[i].second);
        else if(student[i].first==2) woman(a,student[i].second);
    }
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << ' ';
        if((i+1)%20==0) cout << '\n';
    }
    return 0;
}