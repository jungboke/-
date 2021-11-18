#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<vector<int>> a(n,vector<int>(k,0));
    vector<int> ck;
    vector<int> result;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin >> a[i][j];
        }
    }
    for(int i=0;i<k;i++)
    {
        ck.push_back(i);
    }
    vector<int> perm;
    for(int i=0;i<3;i++) perm.push_back(1);
    for(int i=0;i<k-3;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<int> temp;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) temp.push_back(ck[i]); 
        }
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            int maxi = 0;
            for(int j=0;j<temp.size();j++)
            {
                if(maxi<a[i][temp[j]]) maxi = a[i][temp[j]];
            }
            sum += maxi;
        }
        result.push_back(sum);
    }while(next_permutation(perm.begin(),perm.end()));
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}