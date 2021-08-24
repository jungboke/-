#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> answer[11];
vector<int> a;
void go(int start,int end,int level)
{
    if(start==end)
    {
        answer[level].push_back(a[start]);
        return;
    }
    int mid = (start+end)/2;
    answer[level].push_back(a[mid]);
    go(start,mid-1,level+1);
    go(mid+1,end,level+1);
}
int main()
{
    int n;
    cin >> n;
    int m = pow(2,n) - 1;

    for(int i=0;i<m;i++)
    {
        int k;
        cin >> k;
        a.push_back(k);
    }
    go(0,m-1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<answer[i].size();j++)
        {
            cout << answer[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}