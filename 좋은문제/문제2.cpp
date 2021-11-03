#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
char a[5][10001];
int main()
{
    int length;
    for(int i=0;i<5;i++)
    {
        string temp = "";
        cin >> temp;
        length = temp.size();
        for(int j=0;j<temp.size();j++)
        {
            a[i][j] = temp[j];
        }
    }
    string b = ".omln";
    string c = "owln.";
    string d = "..oLn";
    for(int j=0;j<length;j++)
    {
        string temp = "";
        for(int i=0;i<5;i++)
        {
            temp += a[i][j];
        }
        if(temp == b)
        {
            for(int i=0;i<5;i++)
            {
                a[i][j] = c[i];
            }
        }
        else if(temp == c)
        {
            for(int i=0;i<5;i++)
            {
                a[i][j] = b[i];
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<length;j++)
        {
            cout << a[i][j];
        }
        cout << '\n';       
    }
    return 0;
}