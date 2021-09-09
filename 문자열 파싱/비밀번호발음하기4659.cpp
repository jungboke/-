/*
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
*/
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
        bool flag = true;
        bool mflag = false;
        char bword = a[0]-1;
        for(int i=0;i<a.size();i++)
        {
            if(bword==a[i]&&a[i]!='e'&&a[i]!='o')
            {
                flag = false;
                break;
            }
            bword = a[i];
            if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
            {
                mflag = true;
                j_cnt = 0;
                m_cnt++;
            }
            else
            {
                m_cnt = 0;
                j_cnt++;
            }
            if(m_cnt>=3||j_cnt>=3)
            {
                flag = false;
                break;
            }
        }
        if(mflag==false) flag = false;
        if(flag==true) cout << '<' << a << '>' << " is acceptable." << '\n';
        else cout << '<' << a << '>' << " is not acceptable." << '\n';
    }
    return 0;
}






















