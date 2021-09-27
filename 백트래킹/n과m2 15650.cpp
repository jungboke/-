#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[10];
void dfs(vector<int> a,vector<int> temp,int cnt,int start)
{
    if(temp.size()==cnt)
    {
        for(int i=0;i<temp.size();i++)
        {
            cout << temp[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=start;i<a.size();i++)
    {
        if(check[i]==false)
        {
            check[i] = true;
            temp.push_back(a[i]);
            dfs(a,temp,cnt,i+1);
            temp.pop_back();
            check[i] = false;
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        a.push_back(i);
    }
    vector<int> temp;
    dfs(a,temp,m,0);
    return 0;
}
/*
    오름차순 배열에서 dfs진행시, 오름차순 정답을 얻고 싶은경우 start변수를 적용.
*/