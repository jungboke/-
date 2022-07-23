/*
    모두 M인 경우 하나씩 붙이는게 최대.
*/
/*
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
*/
#include <bits/stdc++.h>
using namespace std;
string change(string a)
{
    string num = "";
    if(a[a.size()-1]=='K') num += '5';
    else num += '1';
    for(int i=0;i<a.size()-1;i++) num += '0';
    return num;
}
string change1(string a)
{
    string answer = "";
    string temp = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='K')
        {
            temp += a[i];
            answer += change(temp);
            temp = "";
        }
        else temp += a[i];
    }
    if(temp!="")
    {
        for(int i=0;i<temp.size();i++) answer += '1';
    }
    return answer;
}
string change2(string a)
{
    string answer = "";
    string temp = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='K')
        {
            if(temp!="") answer += change(temp);
            answer += '5';
            temp = "";
        }
        else temp += a[i];
    }
    if(temp!="") answer += change(temp);
    return answer;
}
int main()
{
    string a;
    cin >> a;
    string maxi = change1(a);
    string mini = change2(a);
    cout << maxi << '\n';
    cout << mini << '\n';
    return 0;
}