/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    map<string,int> map1;
    int total = 0;
    while(true)
    {
        string x;
        getline(cin,x);
        if(cin.eof()) break;
        map1[x]++;
        total++;
    }
    for(auto k : map1)
    {
        string a = k.first;
        double b = k.second;
        cout << a << ' ' << (b/total)*100 << '\n'; 
    }
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.setf(ios::fixed);
    cout.precision(4);
    map<string,int> map1;
    int cnt = 0;
    while(true)
    {
        string x;
        getline(cin,x);
        if(cin.eof()) break;
        map1[x]++;
        cnt++;
    }
    for(auto k:map1)
    {
        cout << k.first << ' ' << ((double)k.second/cnt)*100 << '\n';
    }
    return 0;
}
/*
    getline(cin,x,'\n') 형태는 default로 /n만나면 종료되고,
    cin.getline(x,100,'\n') 형태는 글자수가 99가 넘거나, /n을 만나면 종료됨.
    cout.setf(ios::fixed)로 소수점 아래부분만 출력범위 설정.
    cout.precision(4)를 연속해서 쓰면 소수점아래 4자리만 출력. 원래는 총합 4자리.
    if(cin.eof())로 eof만나면 종료되게 설정.
*/