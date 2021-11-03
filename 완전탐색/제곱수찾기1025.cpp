/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> result;
int N,M;
void check(string num)
{
    int k = stoi(num);
    int c = sqrt(k);
    if(c*c==k) result.push_back(k);
    reverse(num.begin(),num.end());
    k = stoi(num);
    c = sqrt(k);
    if(c*c==k) result.push_back(k);
    return;
}
void go(vector<vector<int>> a,int x,int y)
{
    for(int i=-N;i<N;i++)
    {
        for(int j=-M;j<M;j++)
        {
            if(i==0&&j==0)
            {
                check(to_string(a[x][y]));
                continue;
            }
            int c = x;
            int d = y;
            string temp = "";
            while(c>=0&&c<N&&d>=0&&d<M)
            {
                temp += to_string(a[c][d]);
                check(temp);
                c+=i;
                d+=j;
            }
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    N=n;M=m;
    vector<vector<int>> a(n,vector<int>(m,0));
    for(int i=0;i<n;i++)
    {
        string temp;
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j]-48;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            go(a,i,j);
        }
    }
    if(result.empty()) cout << -1 << '\n';
    else cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
char a[10][10];
int N,M;
vector<int> result;
void test(int x,int y)
{
    for(int i=-N+1;i<N;i++)
    {
        for(int j=-M+1;j<M;j++)
        {
            string temp = "";
            int nx = x;
            int ny = y;
            while(nx>=0&&nx<N&&ny>=0&&ny<M)
            {
                temp += a[nx][ny];
                int num = stoi(temp);
                int k = sqrt(num);
                if(k*k==num) result.push_back(num);
                nx+=i;
                ny+=j;
                if(i==0&&j==0) break;
            }
        }
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    N=n;M=m;
    for(int i=0;i<n;i++)
    {
        string temp = "";
        cin >> temp;
        for(int j=0;j<m;j++)
        {
            a[i][j] = temp[j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            test(i,j);
        }
    }
    if(result.size()==0) cout << -1 << '\n';
    else cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}














