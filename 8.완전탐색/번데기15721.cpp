#include <vector>
#include <algorithm>
#include <iostream>
#define INF 1000000000
using namespace std;

int main()
{
    int n,m,c;
    cin >> n >> m >> c;
    int b_cnt = 0;
    int d_cnt = 0;
    int idx = 0;
    for(int i=1;i<=10000;i++)
    {
        string temp = "";
        temp += "bdbd";
        for(int j=0;j<i+1;j++) temp += 'b';
        for(int j=0;j<i+1;j++) temp += 'd';
        for(int k=0;k<temp.size();k++)
        {
            if(temp[k]=='b') b_cnt++;
            else if(temp[k]=='d') d_cnt++;
            if((c==0&&b_cnt==m)||(c==1&&d_cnt==m))
            {
                cout << idx << '\n';
                return 0; 
            }
            idx = (idx+1)%n;
        } 
    }
    return 0;
}