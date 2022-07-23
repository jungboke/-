/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int cal(vector<int> a,vector<char> b)
{
    for(int i=0;i<b.size();i++)
    {
        if(b[i] == ' ')
        {
            a[i] = a[i]*10 + a[i+1];
            a.erase(a.begin()+i+1);
            b.erase(b.begin()+i);
            i--;
        }
    }
    while(a.size()!=1)
    {
        if(b[0]=='+')
        {
            a[0] = a[0]+a[1];
            a.erase(a.begin()+1);
            b.erase(b.begin()+0);
        }
        else if(b[0]=='-')
        {
            a[0] = a[0]-a[1];
            a.erase(a.begin()+1);
            b.erase(b.begin()+0);
        }
        else if(b[0]==' ')
        {
            a[0] = a[0]*10+a[1];
            a.erase(a.begin()+1);
            b.erase(b.begin()+0);
        }
    }
    return a[0];
}
void go(vector<int> a,vector<char> b,vector<vector<char>> &result)
{
    if(b.size()==a.size()-1)
    {
        int ans = cal(a,b);
        if(ans == 0)
        {
            result.push_back(b);
        }
        return;
    }
    b.push_back(' ');
    go(a,b,result);
    b.pop_back();
    b.push_back('+');
    go(a,b,result);
    b.pop_back();
    b.push_back('-');
    go(a,b,result);
    b.pop_back();
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        for(int i=1;i<=n;i++) a.push_back(i);
        vector<vector<char>> result;
        vector<char> temp;
        go(a,temp,result);
        for(int i=0;i<result.size();i++)
        {
            string temp = "";
            for(int j=0;j<result[i].size();j++)
            {
                temp += to_string(a[j]) + result[i][j];
            }
            temp += to_string(a[n-1]);
            cout << temp << '\n';
        }
        cout << '\n';
    }

    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<char>> result;
int cal(vector<int> a,vector<char> op)
{
    for(int i=0;i<op.size();i++)
    {
        if(op[i]==' ')
        {
            a[i] = a[i] * 10 + a[i+1];
            a.erase(a.begin()+i+1);
            op.erase(op.begin()+i);
            i--;
        }
    }
    int sum = a[0];
    for(int i=0;i<op.size();i++)
    {
        if(op[i]=='+') sum += a[i+1];
        else if(op[i]=='-') sum -=  a[i+1];
    }
    return sum;
}
void go(vector<int> a,vector<char> op,int idx,int max)
{
    if(idx==max-1)
    {
        if(cal(a,op)==0)
        {
            result.push_back(op);
        }
        return;
    }
    op.push_back(' ');
    go(a,op,idx+1,max);
    op.pop_back();
    op.push_back('+');
    go(a,op,idx+1,max);
    op.pop_back();
    op.push_back('-');
    go(a,op,idx+1,max);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        result.clear();
        int n;
        cin >> n;
        vector<int> a;
        for(int i=1;i<=n;i++)
        {
            a.push_back(i);
        }
        vector<char> temp;
        go(a,temp,0,n);
        for(int i=0;i<result.size();i++)
        {
            string temp = "";
            for(int j=0;j<result[i].size();j++)
            {
                temp += to_string(a[j]) + result[i][j];
            }
            temp += to_string(a[n-1]);
            cout << temp << '\n';
        }
        cout << '\n';
    }
    return 0;
}
// 연산자 배열과 숫자 배열의 합을 구하는 최적의 방법.






















