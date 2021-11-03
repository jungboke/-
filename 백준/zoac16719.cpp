#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[101];
string change(string a)
{
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
        {
            a.erase(a.begin()+i);
            i--;
        } 
    }
    return a;
}
int main()
{
    string a;
    cin >> a;
    string temp = "";
    int size = a.size();
    for(int i=0;i<size;i++)
    {
        temp += '0';
    }
    bool flag = true;
    while(flag==true)
    {
        flag = false;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]=='0') flag = true;
        }
        string mini = "0";
        int min_idx = 0;
        for(int i=0;i<a.size();i++)
        {
            if(check[i]==true) continue;
            string temp2 = temp;
            temp2[i] = a[i];
            temp2 = change(temp2);
            if(mini=="0"||mini>temp2)
            {
                mini = temp2;
                min_idx = i;
            }
        }
        temp[min_idx] = a[min_idx];
        check[min_idx] = true;
        if(flag==true) cout << change(temp) << '\n';
    }
    return 0;
}
/*
    문제의 핵심이 되는 부분은 문자들이 추가될때 앞,중간,뒤 어느 부분에 추가되는지 판별하는 것.
*/