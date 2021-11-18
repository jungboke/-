/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,k,c;
    cin >> n >> d >> k >> c;
    vector<int> a(n);
    unordered_map<int,int> map1;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    map1[c]++;
    for(int i=0;i<k;i++)
    {
        map1[a[i]]++;
    }
    int maxi = map1.size();
    int sum = maxi;
    for(int i=k;i<n+k;i++)
    {
        int x = (i-k)%n;
        int y = i%n;
        if(map1[a[x]]>1) map1[a[x]]--;
        else
        {
            sum--;
            map1[a[x]]--;
        }
        if(map1[a[y]]>0) map1[a[y]]++;
        else
        {
            sum++;
            map1[a[y]]++;
        }
        if(maxi<sum)
        {
            maxi = sum;
        }
    }
    cout << maxi << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
vector<int> result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,d,k,c;
    cin >> n >> d >> k >> c;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    unordered_map<int,int> map1;
    for(int i=0;i<k;i++)
    {
        map1[a[i]]++;
    }
    map1[c]++;
    result.push_back(map1.size());
    for(int i=k;i<n+k;i++)
    {
        map1[a[i%n]]++;
        map1[a[(i-k)%n]]--;
        if(map1[a[(i-k)%n]]==0) map1.erase(a[(i-k)%n]);
        result.push_back(map1.size());
    }
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}














