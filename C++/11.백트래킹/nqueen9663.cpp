#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int answer = 0;
bool check_col[16];
bool check_dig1[32];
bool check_dig2[32];
bool check(int row,int col,int max)
{
    if(check_col[col]==false)
    {
        if(check_dig1[row+col]==false)
        {
            if(check_dig2[col-row+max]==false)
            {
                return true;
            }
        }
    }
    return false;
}
void dfs(int row,int max)
{
    if(row==max)
    {
        answer++;
    }
    for(int col=0;col<max;col++)
    {
        if(check(row,col,max)==true)
        {
            check_col[col] = true;
            check_dig1[col+row] = true;
            check_dig2[col-row+max] = true;   
            dfs(row+1,max);
            check_col[col] = false;
            check_dig1[col+row] = false;
            check_dig2[col-row+max] = false;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    dfs(0,n);
    cout << answer << '\n';
    return 0;
}