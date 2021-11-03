#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string a;
        getline(cin,a);
        unordered_map<char,int> map1;
        int maxi = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==' ') continue;
            map1[a[i]]++;
            if(maxi<map1[a[i]]) maxi = map1[a[i]];
        }
        int cnt = 0;
        char answer;
        for(auto k:map1)
        {
            if(k.second==maxi)
            {
                cnt++;
                answer = k.first;
            }
        }
        if(cnt>1) cout << "?" << '\n';
        else if(cnt==1) cout << answer << '\n';
    }
    return 0;
}
/*
    cin을 쓰면 버퍼에 \n이 남게 되고 getline은 \n까지 다읽음. 그래서 cin이후에 getline쓰려면
    cin.ignore()사용해야함. 그리고 getline은 \n까지 다읽긴하지만 \n은 입력으로 취급안함.
*/