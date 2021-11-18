/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> result;
bool check[20];
long long cal(vector<int> a,vector<char> op)
{
    long long sum = a[0];
    for(int i=0;i<op.size();i++)
    {
        if(op[i]=='+')
        {
            sum += a[i+1];
        }
        else if(op[i]=='-')
        {
            sum -= a[i+1];
        }
        else
        {
            sum *= a[i+1];
        }
    }
    return sum;
}
void dfs(int idx,int max,vector<int> temp)
{
    if(idx==max)
    {
        result.push_back(temp);
        return;
    }
    if(check[idx-1]!=true||idx==0) 
    {
        temp.push_back(idx);
        check[idx] = true;
        dfs(idx+1,max,temp);
        temp.pop_back();
        check[idx] = false;
        dfs(idx+1,max,temp);
    }
    else
    {
        dfs(idx+1,max,temp);
    }
}
int main()
{
    int n;
    cin >> n;
    string m;
    cin >> m;
    vector<int> a;
    vector<char> op;
    for(int i=0;i<m.size();i++)
    {
        if(isdigit(m[i])!=0) a.push_back(m[i]-48);
        else op.push_back(m[i]);
    }
    vector<int> temp;
    dfs(0,op.size(),temp); 
    vector<long long> answer;
    for(int i=0;i<result.size();i++)
    {
        vector<int> temp = result[i];
        vector<int> tmp_a = a;
        vector<char> tmp_op = op;
        int k = 0;
        for(int j=0;j<op.size();j++)
        {
            if(find(temp.begin(),temp.end(),j)!=temp.end())
            {
                if(op[j]=='+')
                {
                    tmp_a[j-k] = tmp_a[j-k]+tmp_a[j+1-k];
                    tmp_a.erase(tmp_a.begin()+j+1-k);
                    tmp_op.erase(tmp_op.begin()+j-k);
                    k++;
                }
                else if(op[j]=='-')
                {
                    tmp_a[j-k] = tmp_a[j-k]-tmp_a[j+1-k];
                    tmp_a.erase(tmp_a.begin()+j+1-k);
                    tmp_op.erase(tmp_op.begin()+j-k);
                    k++;
                }
                else
                {
                    tmp_a[j-k] = tmp_a[j-k]*tmp_a[j+1-k];
                    tmp_a.erase(tmp_a.begin()+j+1-k);
                    tmp_op.erase(tmp_op.begin()+j-k);
                    k++;
                }
            }
        }
        answer.push_back(cal(tmp_a,tmp_op));
    }
    cout << *max_element(answer.begin(),answer.end()) << '\n';
    return 0;
}*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<vector<int>> result;
bool check[20];
void dfs(vector<char> op,int idx,vector<int> temp)
{
    if(idx==op.size())
    {
        result.push_back(temp);
        return;
    }
    temp.push_back(0);
    dfs(op,idx+1,temp);
    temp.pop_back();
    if(check[idx-1]!=true||idx==0)
    {
        check[idx] = true;
        temp.push_back(1);
        dfs(op,idx+1,temp);
        temp.pop_back();
        check[idx] = false;
    }
}
int cal(vector<int> num,vector<char> op)
{
    int sum = num[0];
    for(int i=0;i<op.size();i++)
    {
        if(op[i]=='+')
        {
            sum += num[i+1];
        }
        else if(op[i]=='-')
        {
            sum -= num[i+1];
        }
        else if(op[i]=='*')
        {
            sum *= num[i+1];
        }
    }
    return sum;
}
void trim(vector<int> &num,vector<char> &op,vector<int> temp)
{
    int k = 0;
    for(int i=0;i<op.size();i++)
    {
        if(temp[i+k]==1)
        {
            if(op[i]=='+')
            {
                num[i] = num[i] + num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i--;
                k++;
            }
            else if(op[i]=='-')
            {
                num[i] = num[i] - num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i--;
                k++;
            }
            else if(op[i]=='*')
            {
                num[i] = num[i] * num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i--;
                k++;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> num;
    vector<char> op;
    for(int i=0;i<n;i++)
    {
        if(isdigit(a[i])!=0) num.push_back(a[i]-48);
        else op.push_back(a[i]);
    }
    vector<int> temp;
    dfs(op,0,temp);
    vector<int> answer;
    for(int i=0;i<result.size();i++)
    {
        vector<int> tmp_num = num;
        vector<char> tmp_op = op;
        trim(tmp_num,tmp_op,result[i]);
        answer.push_back(cal(tmp_num,tmp_op));
    }
    cout << *max_element(answer.begin(),answer.end());
    return 0;
}
















/*
    문제풀기전에 먼저 태블릿으로 설계해보기.
    백트래킹 구성.
*/