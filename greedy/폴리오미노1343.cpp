#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a;
    cin >> a;
    a += '.';
    string temp = "";
    string answer = "";
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='.')
        {
            if(temp.size()%2==1)
            {
                cout << -1 << '\n';
                return 0;
            }
            else
            {
                int x = temp.size()/4;
                for(int i=0;i<x;i++) answer += "AAAA";
                x = (temp.size()%4)/2;
                for(int i=0;i<x;i++) answer += "BB";
                answer += '.';
                temp = "";
            }
        }
        else temp += a[i];
    }
    answer.erase(answer.end()-1);
    cout << answer << '\n';
    return 0;
}