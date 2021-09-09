/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int maxi = 0;
    int odd = 0;
    int start = 0;
    int end = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==1)
        {
            if(odd+1>m) break;
            else odd++;
        }
        end = i;
    }
    maxi = end-start+1-odd;
    while(end<n)
    {
        if(a[start]%2==1) odd-=1;
        start++;
        end++;
        while(end<n)
        {
            if(a[end]%2==1)
            {
                odd++;
                if(odd<=m)
                {
                    if(end-start+1-odd>maxi) maxi = end-start+1-odd;
                    end++;
                }
                else
                {
                    odd--;
                    end--;
                    break;
                }
            }
            else
            {
                if(end-start+1-odd>maxi) maxi = end-start+1-odd;
                end++;
            }           
        }
    }
    cout << maxi << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int start = 0;
    int end = 0;
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==1)
        {
            if(cnt+1>m) break;
            cnt++;
        }
        end = i;
    }
    int maxi = end-start+1-cnt;
    while(end<n)
    {
        if(a[start]%2==1) cnt--;
        start++;
        end++;
        while(end<n)
        {
            if(a[end]%2==1) cnt++;
            if(cnt>m)
            {
                end--;
                cnt--;
                break;
            }
            if(maxi<end-start+1-cnt) maxi = end-start+1-cnt;
            end++;
        }
    }
    cout << maxi << '\n';
    return 0;
}






















