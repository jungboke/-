#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++)    
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long answer = 0;
    for(int i=0;i<n-2;i++)
    {
        int start = i;
        int mid = i+1;
        int end = n-1;
        int j=n;
        while(mid<end)
        {
            int sum = a[mid] + a[end];
            if(sum+a[start]>0) end--;
            else if(sum+a[start]<0) mid++;
            else if(sum+a[start]==0)
            {
                if(a[mid]==a[end])
                {
                    answer += end-mid;
                }
                else
                {
                    auto k1 = lower_bound(a.begin(),a.end(),a[end]);
                    auto k2 = upper_bound(a.begin(),a.end(),a[end]);
                    answer += k2-k1;
                }
                mid++;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
/*
    두용액 문제와 비슷한데, a[mid]+a[end]==0 이 되는 경우를 잘 커버해야함.
*/