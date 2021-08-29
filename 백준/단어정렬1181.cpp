#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
bool cmp(string a,string b)
{
    if(a.size()==b.size()) return a<b;
    return (a.size()<b.size());
}
int main()
{
    int n;
    cin >> n;
    set<string> s;
    for(int i=0;i<n;i++)
    {
        string x;
        cin >> x;
        s.insert(x);
    }
    vector<string> a;
    a.assign(s.begin(),s.end());
    sort(a.begin(),a.end(),cmp);
    for(int i=0;i<a.size();i++)
    {
        cout << a[i] << '\n';
    }
    return 0;
}