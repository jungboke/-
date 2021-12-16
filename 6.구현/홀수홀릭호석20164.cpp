/* 
    굳이 permutation안쓰고 다중for문으로 풀수있으면 안쓰는게 좋음(ex 10개중 2개의 값을 고를때 2중for
    문이 효과적임), substr의 두번째인자 안들어가면 마지막까지,
    한배열을 n등분하는 방법의 정석.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
using namespace std;
vector<int> result;
vector<vector<int>> go(int a)
{
    vector<vector<int>> all;
    vector<int> idx;
    vector<int> perm;
    for(int i=0;i<a;i++)
    {
        idx.push_back(i);
    }
    for(int i=0;i<2;i++) perm.push_back(1);
    for(int i=0;i<idx.size()-2;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<int> temp;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) temp.push_back(idx[i]);
        }
        all.push_back(temp);
    }while(next_permutation(perm.begin(),perm.end()));
    return all;
}
void check(string num,int odd)
{
    if(num.size()==1)
    {
        int temp = num[0] - 48;
        if(temp%2==1) odd++;
        result.push_back(odd);
        return;
    }
    for(int i=0;i<num.size();i++)
    {
        int x = num[i]-48;
        if(x%2==1) odd++;
    }
    if(num.size()==2)
    {
        long long next = 0;
        for(int i=0;i<2;i++)
        {
            int x = num[i]-48;
            next += x;
        }
        check(to_string(next),odd);
    }
    else
    {
        vector<vector<int>> temp;
        temp = go(num.size());
        for(int i=0;i<temp.size();i++)
        {
            int start = temp[i][0];
            int end = temp[i][1];
            if(end==num.size()-1) continue;
            long long one = stoll(num.substr(0,start+1));
            long long two = stoll(num.substr(start+1,end-start));
            long long three = stoll(num.substr(end+1,num.size()-1-end));
            long long next = one + two + three;
            check(to_string(next),odd);
        }    
    }
}
int main()
{
    long long n;
    cin >> n;
    string num = to_string(n);
    check(num,0);
    cout << *min_element(result.begin(),result.end()) << ' ' << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> result;
void dfs(string a,int odd)
{
    if(a.size()==1)
    {
        int num = a[0] - 48;
        if(num%2==1) odd++;
        result.push_back(odd);
        return;
    }
    else if(a.size()==2)
    {
        for(int i=0;i<a.size();i++)
        {
            if((a[i]-48)%2==1) odd++;
        }
        int num1 = a[0]-48;
        int num2 = a[1]-48;
        dfs(to_string(num1+num2),odd);
    }
    else
    {
        for(int i=0;i<a.size();i++)
        {
            if((a[i]-48)%2==1) odd++;
        }
        for(int i=0;i<a.size()-2;i++)
        {
            for(int j=i+1;j<a.size()-1;j++)
            {
                int num1 = stoi(a.substr(0,i+1));
                int num2 = stoi(a.substr(i+1,j-i));
                int num3 = stoi(a.substr(j+1));
                dfs(to_string(num1+num2+num3),odd);
            }
        }
    }
}
int main()
{
    string a;
    cin >> a;
    dfs(a,0);
    cout << *min_element(result.begin(),result.end()) << ' ' << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}