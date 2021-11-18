/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> failfunc(string p)
{
    int m = p.size();
    vector<int> a(m);
    a[0] = 0;
    int j = 0;
    for(int i=1;i<m;i++)
    {
        while(j>0&&p[i]!=p[j]) j=a[j-1];
        if(p[i]==p[j])
        {
            a[i] = j+1;
            j+=1;
        }
        else a[i] = 0;
    }
    return a;
}
vector<int> kmp(string s,string p)
{
    vector<int> a = failfunc(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int j = 0;
    for(int i=0;i<n;i++)
    {
        while(j>0&&s[i]!=p[j]) j=a[j-1];
        if(s[i]==p[j])
        {
            if(j==m-1)
            {
                ans.push_back(i-m+1);
                j=a[j];
            }
            else j+=1;
        } 
    }
    return ans; 
}
int main()
{
    string s,p;
    cin >> s >> p;
    vector<int> result = kmp(s,p);
    if(result.size()==0) cout << 0 << '\n';
    else cout << 1 << '\n';   
    return 0;
}
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> failfunc(string p)
{
    int m = p.size();
    vector<int> a(m);
    a[0] = 0;
    int j=0;
    for(int i=1;i<m;i++)
    {
        while(j>0&&p[i]!=p[j]) j=a[j-1];
        if(p[i]==p[j])
        {
            a[i] = j+1;
            j+=1;
        }
        else a[i] = 0; 
    }
    return a;
}
vector<int> kmp(string s,string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> a = failfunc(p);
    vector<int> ans;
    int j=0;
    for(int i=0;i<n;i++)
    {
        while(j>0&&s[i]!=p[j]) j = a[j-1];
        if(s[i]==p[j])
        {
            if(j==m-1)
            {
                ans.push_back(i-m+1);
                j=a[j];
            }
            else j+=1;
        }
    }
    return ans;
}
int main()
{
    string s,p;
    cin >> s >> p;
    vector<int> result = kmp(s,p);
    if(result.empty()) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<int> failfunc(string p)
{
    int m = p.size();
    vector<int> a(m);
    a[0] = 0;
    int j = 0;
    for(int i=1;i<m;i++)
    {
        while(j>0&&p[i]!=p[j]) j = a[j-1];
        if(p[i]==p[j])
        {
            a[i] = j+1;
            j+=1;
        }
        else a[i] = 0;
    }
    return a;
}
vector<int> kmp(string s,string p)
{
    int n = s.size();
    int m = p.size();
    vector<int> a = failfunc(p);
    vector<int> result;
    int j = 0;
    for(int i=0;i<n;i++)
    {
        while(j>0&&s[i]!=p[j]) j = a[j-1];
        if(s[i]==p[j])
        {
            if(j==m-1)
            {
                result.push_back(i-m+1);
                j = a[j];
            }
            else j++;
        }
    }
    return result;
}
int main()
{
    string s,p;
    cin >> s >> p;
    vector<int> answer = kmp(s,p);
    if(answer.size()==0) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}















/*
    kmp알고리즘 적용방식 익히기.(문자열내에 원하는 문자열찾기)
    failfunc함수의 vector에서 a[i]의 값은 다음에 같아야할 인덱스임.
*/















