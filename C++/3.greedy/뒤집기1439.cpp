#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    string temp = "";
    char last = a[0] - 1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=last) temp += a[i];
        last = a[i];
    }
    int one = 0;
    int zero = 0;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='1') one++;
        else if(temp[i]=='0') zero++;
    }
    cout << min(one,zero) << '\n';
    return 0;
}