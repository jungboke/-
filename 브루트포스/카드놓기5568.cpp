#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> a;
    vector<int> perm;
    set<string> s; 
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i=0;i<k;i++) perm.push_back(1);
    for(int i=0;i<n-k;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<int> vec;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) vec.push_back(a[i]);
        }
        sort(vec.begin(),vec.end());
        do
        {
            string temp = "";
            for(int i=0;i<vec.size();i++)
            {
                temp+=to_string(vec[i]);
            }
            s.insert(temp);
        } while (next_permutation(vec.begin(),vec.end()));
        
    } while (next_permutation(perm.begin(),perm.end()));
    cout << s.size() << '\n';
    return 0;
}