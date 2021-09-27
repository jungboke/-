#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int a[51][51];
vector<int> result;
int main()
{
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> ch;
    vector<pair<int,int>> nh;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==2)
            {
                ch.push_back(make_pair(i,j));
            }
            else if(a[i][j]==1)
            {
                nh.push_back(make_pair(i,j));
            }
        }
    }
    vector<int> perm;
    for(int i=0;i<k;i++) perm.push_back(1);
    for(int i=0;i<ch.size()-k;i++) perm.push_back(0);
    sort(perm.begin(),perm.end());
    do
    {
        vector<pair<int,int>> temp;
        int sum = 0;
        for(int i=0;i<perm.size();i++)
        {
            if(perm[i]==1) temp.push_back(ch[i]);
        }
        for(int i=0;i<nh.size();i++)
        {
            int sx = nh[i].first;
            int sy = nh[i].second;
            int mini = 99999999;
            for(int j=0;j<temp.size();j++)
            {
                int ex = temp[j].first;
                int ey = temp[j].second;
                if(abs(sx-ex)+abs(sy-ey)<mini) mini = abs(sx-ex) + abs(sy-ey);
            }
            sum += mini;
        }
        result.push_back(sum);

    }while(next_permutation(perm.begin(),perm.end()));
    cout << *min_element(result.begin(),result.end()) << '\n';
    return 0;
}