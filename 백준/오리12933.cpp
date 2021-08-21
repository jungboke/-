#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    string b = "quack";
    int cnt = 0;
    bool flag = true;
    while(a.size()!=0)
    {
        int k = 0;
        int how = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==b[k])
            {
                a.erase(a.begin()+i);
                k++;
                i--;
            }
            if(k==b.size())
            {
                how++;
                k = 0;
            }
        }
        if(k!=0)
        {
            flag = false;
            break;
        }
        else
        {
            if(how==0)
            {
                flag = false;
                break;
            }
            else cnt++;
        }
    }
    if(flag==false) cout << -1 << '\n';
    else cout << cnt << '\n';
    return 0;
}