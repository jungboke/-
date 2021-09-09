/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
bool check(string a)
{
    bool flag = true;
    set<char> s;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0') return false;
        s.insert(a[i]);
    }
    if(s.size()!=a.size()) flag = false;
    return flag;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(3,0));
    for(int i=0;i<n;i++)
    {
        cin >> a[i][0];
        cin >> a[i][1];
        cin >> a[i][2];
    }
    int answer = 111;
    int result = 0;     
    while(answer<=999)
    {
        string temp = to_string(answer);
        bool flag = true;
        if(check(temp)==false) flag = false;
        for(int i=0;i<n;i++)
        {
            string ans = to_string(a[i][0]);
            int strike = 0;
            int ball = 0;
            for(int j=0;j<3;j++)
            {
                if(ans[j]==temp[j]) strike++;
                else
                {
                    for(int k=0;k<3;k++)
                    {
                        if(temp[k]==ans[j])
                        {
                            ball++;
                            break;
                        }
                    }
                }
            }
            if(!(strike==a[i][1]&&ball==a[i][2]))
            {
                flag = false;
                break;
            }
        }
        if(flag==true) result++;
        answer++;
    }
    cout << result << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
bool check(int num)
{
    bool flag = true;
    set<char> s;
    string a = to_string(num);
    for(int i=0;i<3;i++)
    {
        if(a[i]=='0')
        {
            flag = false;
            break;
        }
        s.insert(a[i]);
    }
    if(s.size()!=a.size()) flag = false;
    
    return flag;
}
pair<int,int> compare(int a,int b)
{
    string str_a = to_string(a);
    string str_b = to_string(b);
    int strike = 0;
    int ball = 0;
    for(int i=0;i<str_b.size();i++)
    {
        if(str_b[i]==str_a[i])
        {
            strike++;
            continue;
        }
        else
        {
            for(int j=0;j<str_a.size();j++)
            {
                if(str_a[j]==str_b[i])
                {
                    ball++;
                    break;
                }
            }
        }
    }
    return (make_pair(strike,ball));
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a;
    for(int i=0;i<n;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        vector<int> temp;
        temp.push_back(x);
        temp.push_back(y);
        temp.push_back(z);
        a.push_back(temp);
    }
    int num = 100;
    int answer = 0;
    while(num<=999)
    {
        if(check(num)==false)
        {
            num++;
            continue;
        }
        bool flag = true;
        for(int i=0;i<n;i++)
        {
            vector<int> temp = a[i];
            auto pair = compare(num,temp[0]);
            if(!(pair.first==temp[1]&&pair.second==temp[2]))
            {
                flag = false;
                break;
            }
        }
        if(flag==true) answer++;
        num++;
    }
    cout << answer << '\n';
    return 0;
}






















