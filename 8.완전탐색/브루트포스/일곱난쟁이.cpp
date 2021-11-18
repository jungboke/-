#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {

    vector<int> a;
    vector<int> temp;
    for(int i=0;i<9;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<7;i++)
    {
        temp.push_back(1);
    }
    for(int i=0;i<2;i++)
    {
        temp.push_back(0);
    }
    sort(temp.begin(),temp.end());
    do
    {
        int sum = 0;
        vector<int> temp2;
        for(int i=0;i<temp.size();i++)
        {
            if(temp[i]==1)
            {
                temp2.push_back(a[i]);
                sum += a[i];
            }
        }
        if(sum==100)
        {
            for(int i=0;i<temp2.size();i++) cout << temp2[i] << '\n';
            break;
        }
    }while(next_permutation(temp.begin(),temp.end()));
    return 0;
}