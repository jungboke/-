#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
vector<long long> result;
long long change(vector<int> temp)
{
    long long num = 0;
    for(int i=0;i<temp.size();i++)
    {
        num = num*10+temp[i];
    }
    return num;
}
void dfs(vector<int> temp,int idx)
{
    if(temp.size()==10)
    {
        return;
    }
    for(int i=0;i<10;i++)
    {
        if(idx==-1||temp[idx]>i)
        { 
            temp.push_back(i);
            result.push_back(change(temp));
            dfs(temp,idx+1);
            temp.pop_back();
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> temp;
    dfs(temp,-1);
    sort(result.begin(),result.end());
    if(n>result.size()) cout << -1 << '\n';
    else cout << result[n-1] << '\n';
    return 0;
}
/*
    문제의 핵심은 가장 긴 감소하는 숫자가 9876543210 이라는 것을 파악하는 일임.
    temp 벡터의 사이즈가 10을 넘어가면 감소하는 숫자가 존재할수 없으므로 재귀함수의 break로 설정함.
    모든 감소하는 숫자를 구한후 sorting해서 답을 구함. 실패한 이유는 0 1 10 2 순으로
    측정하여 sorting이 되지 않았음.
*/