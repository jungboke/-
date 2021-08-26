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