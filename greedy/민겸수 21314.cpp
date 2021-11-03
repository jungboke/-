#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
string change(string temp)
{
    string answer = "1";
    int mcount = -1;
    int kcount = 0;
    for(int i=0;i<temp.size();i++)
    {
        if(temp[i]=='M') mcount++;
        else if(temp[i]=='K') kcount++;
    }
    if(kcount==1)
    {
        answer = "5";
        mcount++;
    }
    for(int i=0;i<mcount;i++) answer += '0';
    return answer;  
}
int main()
{
    string a;
    cin >> a;
    string answer = "";
    string answer2 = "";
    string temp = "";
    string temp2 = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='K')
        {
            temp += a[i];
            answer += change(temp);
            temp = "";
            if(temp2!="") answer2 += change(temp2);
            answer2 += change("K");
            temp2 = "";
        }
        else
        {
            temp += a[i];
            temp2 += a[i];
        }
    }
    for(int i=0;i<temp.size();i++) answer += '1';
    if(temp2!="") answer2 += change(temp2);
    cout << answer << '\n';
    cout << answer2 << '\n';
    return 0;
}
/*
    모두 M인 경우 하나씩 붙이는게 최대.
*/