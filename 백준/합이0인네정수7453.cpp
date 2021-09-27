#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long a[4][4001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> a[j][i];
        }
    }
    vector<long long> ab;
    vector<long long> cd;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ab.push_back(a[0][i]+a[1][j]);
            cd.push_back(a[2][i]+a[3][j]);
        }
    }
    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());
    long long answer = 0;
    for(int i=0;i<ab.size();i++)
    {
        long long x = ab[i];
        long long start = 0;
        long long end = cd.size()-1;
        while(start<end)
        {
            long long mid = (start+end)/2;
            long long y = cd[mid];
            if(x+y>=0)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            } 
        }
        long long lower_bound = end;
        start = 0;
        end = cd.size()-1;
        while(start<end)
        {
            long long mid = (start+end)/2;
            long long y = cd[mid];
            if(x+y>0)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        long long upper_bound = end;
        answer += (upper_bound-lower_bound);
    }
    cout << answer << '\n';
    return 0;
}
// end설정하는부분에서 잘못됨. cd의 마지막 인덱스+1까지 취급해야함. why) upperbound관련해서 마지막인덱스 이후로 나올수도