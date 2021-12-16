/*
    vector<vector<int>> a 형태로 a를 만들고, vector<int> result에 두번째 큰 값들을 집어넣고
    다시 tmp_a배열로 만들어서 풀려고 해서 실패함. 이제 시뮬레이션 같은 문제는 2중벡터문으로
    구현하지말고 전역배열로 설정하자. index범위만 좁혀서보면 크기가 작아져도 전역배열로 커버가능함.
    result에 저장하는게 아닌 두번째 큰 값찾으면 바로 b배열에 넣어줘야했음. 이걸 몰라서 삽질
    하느라 시간낭비가 너무 심함. 문제푸는 아이디어부터 주석으로 적어놓은다음 풀자.
*/
/*
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
int a[1024][1024];
int b[1024][1024];
void dfs(int x,int y,int n)
{
    if(n==2)
    {
        vector<int> temp;
        temp.push_back(a[x][y]);
        temp.push_back(a[x][y+1]);
        temp.push_back(a[x+1][y]);
        temp.push_back(a[x+1][y+1]);
        sort(temp.begin(),temp.end());
        b[x/2][y/2] = temp[2];
        return;
    }
    dfs(x,y,n/2);
    dfs(x,y+n/2,n/2);
    dfs(x+n/2,y,n/2);
    dfs(x+n/2,y+n/2,n/2);
}
void change(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] = b[i][j];
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    while(true)
    {
        dfs(0,0,n);
        n/=2;
        change(n);
        if(n==1) break;
        memset(b,0,sizeof(b));
    }
    cout << a[0][0] << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int a[1050][1050];
int check(int x,int y,int n)
{
    vector<int> temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int nx = x+i;
            int ny = y+j;
            temp.push_back(a[nx][ny]);
        }
    }
    sort(temp.begin(),temp.end());
    return temp[2];
}
void go(int x,int y,int n)
{
    if(n==2)
    {
        int maxi = check(x,y,n);
        a[x/2][y/2] = maxi;
        return;
    }
    go(x,y,n/2);
    go(x+n/2,y,n/2);
    go(x,y+n/2,n/2);
    go(x+n/2,y+n/2,n/2);
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
        }
    }
    while(n!=1)
    {
        go(0,0,n);
        n = n/2;
    }
    cout << a[0][0] << '\n';
    return 0;
}