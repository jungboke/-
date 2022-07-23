#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    bool flag = true;
    bool flag2= true;
    for(int i=0;i<a.size()/2;i++)
    {
        if(a[i]!=a[a.size()-1-i])
        {
            flag = false;
            break;
        }
        if(a[i]!=a[i+1])
        {
            flag2 = false;
        }
    }
    if(flag==false) cout << a.size() << '\n';
    else if(flag==true&&flag2==true) cout << -1 << '\n';
    else if(flag==true&&flag2==false) cout << a.size()-1 << '\n';  
    return 0;
}