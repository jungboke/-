#include <vector>
#include <algorithm>
#include <iostream>
#include <tuple>
#include <cmath>
using namespace std;
pair<int,int> check(char alp,vector<string> a)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            if(a[i][j] == alp)
            {
                return make_pair(i,j);
            }
        }
    }
    return make_pair(0,0);
}
int main()
{
    vector<string> a;
    string temp = "";
    temp = "qwertyuiop";
    a.push_back(temp);
    temp = "asdfghjkl";
    a.push_back(temp);
    temp = "zxcvbnm";
    a.push_back(temp);
    char l,r;
    cin >> l >> r;
    cin >> temp;
    int sum = 0;
    for(int i=0;i<temp.size();i++)
    {
        int x,y;
        tie(x,y) = check(temp[i],a);
        if(y<=4&&temp[i]!='b')
        {
            int lx,ly;
            tie(lx,ly) = check(l,a);
            sum += abs(lx-x) + abs(ly-y) + 1;
            l = temp[i];
        }
        else if(y>4||temp[i]=='b')
        {
            int rx,ry;
            tie(rx,ry) = check(r,a);
            sum += abs(rx-x) + abs(ry-y) + 1;
            r = temp[i];
        }
    }
    cout << sum << '\n';
    return 0;
}