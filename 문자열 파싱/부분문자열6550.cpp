/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        int idx = 0;
        bool flag = false;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==a[idx]) idx++;
            if(idx>=a.size())
            {
                flag = true;
                break;
            }   
        }
        if(flag==true) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a,b;
        cin >> a >> b;
        if(cin.eof()) break;
        int idx = 0;
        bool flag = false;
        for(int i=0;i<b.size();i++)
        {
            if(b[i]==a[idx])
            {
                idx++;
                if(idx>=a.size())
                {
                    flag = true;
                    break;
                }
            }
        }
        if(flag==true) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
// cin.eof()를 통해 eof()값 받았는지 확인.






















