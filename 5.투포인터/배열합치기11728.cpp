// stl에 merge함수 존재.
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
void merge(vector<int> a,vector<int> b,vector<int> &c)
{
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<a.size()&&j<b.size())
    {
        if(a[i] < b[j])
        {
            c.push_back(a[i++]);
        }
        else
        {
            c.push_back(b[j++]);
        }
    }
    if(i>=a.size())
    {
        while(j<b.size())
        {
            c.push_back(b[j++]);
        }
    }
    else
    {
        while(i<a.size())
        {
            c.push_back(a[i++]);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    merge(a,b,c);
    for(int i=0;i<c.size();i++)
    {
        cout << c[i] << ' ';
    }
    cout << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> result(n+m);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    merge(a.begin(),a.end(),b.begin(),b.end(),result.begin());
    for(int i=0;i<result.size();i++)
    {
        cout << result[i] << ' ';
    } 
    cout << '\n';
    return 0;
}






















