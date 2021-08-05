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

```
+ 백트래킹 dfs, 행렬에서 대각선에 존재여부 판별하는 알고리즘.