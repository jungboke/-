#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    unordered_map<int,int> map1;
    unordered_map<int,int> map2;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        map1[a[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        cin >> b[i];
        map2[b[i]]++;
    }
    for(int i=0;i<m;i++)
    {
        map1[b[i]]--;
        if(map1[b[i]]<=0) map1.erase(b[i]);
    }
    for(int i=0;i<n;i++)
    {
        map2[a[i]]--;
        if(map2[a[i]]<=0) map2.erase(a[i]);
    }
    cout << map1.size()+map2.size() << '\n';
    return 0;
}
/*
    두배열 사이의 교집합을 제거하는데는 map을 활용하는게 find로 제거하는거보다 더빠른듯.
    map2[x]--; 시 x가 map2에 존재하지않아도 -1로 생성됨.
*/