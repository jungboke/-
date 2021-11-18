/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    string m;
    cin >> m;
    int answer = -1;
    string temp = "";
    for(int i=0;i<n.size();i++)
    {
        if(isalpha(n[i])!=0) temp += n[i];
    }
    if(temp.find(m)!=string::npos) answer = 1;
    else answer = 0;
    cout << answer << '\n'; 
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    string temp = "";
    for(int i=0;i<a.size();i++)
    {
        if(isdigit(a[i])!=0) continue;
        temp += a[i];
    }
    if(temp.find(b)==string::npos) cout << 0 << '\n';
    else cout << 1 << '\n';
    return 0;
}






















