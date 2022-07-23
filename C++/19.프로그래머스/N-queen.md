1
```
#include <string>
#include <vector>

using namespace std;
int count = 0;
int N;
bool col_check[20];
bool dig1_check[50];
bool dig2_check[50];
bool check(int row,int col)
{
    bool flag = true;
    if(col_check[col] == true) flag = false;
    if(dig1_check[row+col] == true) flag = false;
    if(dig2_check[row-col+N] == true) flag = false;
    return flag;
}
void dfs(int row)
{
    if(row == N)
    {
        count++;
        return;
    }
    for(int i=0;i<N;i++)
    {
        if(check(row,i) == true)
        {
            col_check[i] = true;
            dig1_check[row+i] = true;
            dig2_check[row-i+N] = true;
            dfs(row+1);
            col_check[i] = false;
            dig1_check[row+i] = false;
            dig2_check[row-i+N] = false;
        }
    }
}
int solution(int n) {
    int answer = 0;
    N=n;
    dfs(0);
    answer = count;
    return answer;
}
```
2
```
#include <string>
#include <vector>

using namespace std;
int result = 0;
bool checkcol[100];
bool checkdis1[100]; // 좌상향
bool checkdis2[100]; // 우상향
bool check(int row,int col,vector<vector<int>> a)
{
    if(checkcol[col]==false&&checkdis1[col-row+a.size()]==false&&checkdis2[col+row]==false)
        return true;
    else return false;
}
void dfs(int idx,vector<vector<int>> a)
{
    if(idx==a.size())
    {
        result++;
        return;
    }
    for(int i=0;i<a.size();i++)
    {
        if(check(idx,i,a)==true)
        {
            checkcol[i] = true;
            checkdis1[i-idx+a.size()] = true;
            checkdis2[i+idx] = true;
            dfs(idx+1,a);
            checkcol[i] = false;
            checkdis1[i-idx+a.size()] = false;
            checkdis2[i+idx] = false;
        }
    }
}
int solution(int n) {
    int answer = 0;
    vector<vector<int>> a(n,vector<int>(n,0));
    dfs(0,a);
    answer = result;
    return answer;
}
```
+ 백트래킹 dfs, 행렬에서 대각선에 존재여부 판별하는 알고리즘.