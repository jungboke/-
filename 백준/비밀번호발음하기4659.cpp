#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    while(true)
    {
        string a;
        cin >> a;
        if(a=="end") break;
        int m_cnt = 0;
        int j_cnt = 0;
        char now = a[0]+1;
        bool flag = true;
        bool flag2 = false;
        for(int i=0;i<a.size();i++)
        {
            if(now==a[i]&&a[i]!='e'&&a[i]!='o')
            {
                flag = false;
                break;
            }
            now = a[i]; 
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            {
                flag2 = true;
                j_cnt = 0;
                m_cnt++;
            }
            else if(isalpha(a[i])!=0)
            {
                m_cnt = 0;
                j_cnt++;
            }
            
            if(j_cnt>=3||m_cnt>=3)
            {
                flag = false;
                break;
            }
        }
        if(flag2==false) flag = false;
        if(flag==true) cout << '<' << a << '>' << " is acceptable." << '\n';
        else cout << '<' << a << '>' << " is not acceptable." << '\n';  
    }

    return 0;
}