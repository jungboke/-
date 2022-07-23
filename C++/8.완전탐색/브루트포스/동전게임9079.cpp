#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check(vector<vector<char>> a)
{
    bool flag = true;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]!=a[0][0])
            {
                flag = false;
            }
        }
    }
    return flag;
}
void change1(vector<vector<char>> &a,int num)
{
    for(int i=0;i<3;i++)
    {
        if(a[num][i]=='T') a[num][i] = 'H';
        else a[num][i] = 'T';
    }
}
void change2(vector<vector<char>> &a,int num)
{
    for(int i=0;i<3;i++)
    {
        if(a[i][num]=='T') a[i][num] = 'H';
        else if(a[i][num]=='H') a[i][num] = 'T';
    }
}
void change3(vector<vector<char>> &a,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(i+j==num)
            {
                if(a[i][j]=='T') a[i][j] = 'H';
                else if(a[i][j]=='H') a[i][j] = 'T';
            }
        }
    }
}
void change4(vector<vector<char>> &a,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(j-i+2==num)
            {
                if(a[i][j]=='T') a[i][j] = 'H';
                else if(a[i][j]=='H') a[i][j] = 'T';
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> result;
        int answer = -1;
        int cnt = 0;
        vector<vector<char>> a(3,vector<char>(3,'0'));
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=0;i<(1<<3);i++)
        {
            vector<vector<char>> tmp_a = a;
            int cnt = 0;
            for(int j=0;j<3;j++)
            {
                if((i&(1<<j))!=0)
                {
                    cnt++;
                    change1(tmp_a,j);
                }
            }
            for(int c=0;c<(1<<3);c++)
            {
                vector<vector<char>> tmp_a2 = tmp_a;
                int cnt2= 0;
                for(int d=0;d<3;d++)
                {
                    if((c&(1<<d))!=0)
                    {
                        cnt2++;
                        change2(tmp_a2,d);
                    }
                }
            }
        }
        if(result.empty()) cout << -1 << '\n';
        else cout << *min_element(result.begin(),result.end()) << '\n';
    }
    return 0;
}