#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check(string a,int idx)
{
    a.erase(idx,1);
    int start = 0;
    int end = a.size()-1;
    bool flag = true;
    while(start<end)
    {
        if(a[start]!=a[end])
        {
            flag = false;
            break;
        }
        start++;
        end--;
    }
    return flag;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a;
        cin >> a;
        int answer = 0;
        int start = 0;
        int end = a.size()-1;
        while(start<end)
        {
            if(a[start]!=a[end])
            {
                if((end-1>start&&a[end-1]==a[start])||(start+1<end&&a[start+1]==a[end]))
                {   
                    if(check(a,start)==true||check(a,end)==true) answer = 1;
                    else answer = 2;
                    break;
                }
                else
                {
                    answer = 2;
                    break;
                }
            }
            start++;
            end--;
        }
        cout << answer << '\n';
    }
    return 0;
}
// string의 erase는 (a,b) a:시작인덱스 b:지울개수
// vector의 erase는 (a,b) a:시작iterator b:마지막iterator