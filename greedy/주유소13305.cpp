#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> dist(n-1);
    for(int i=0;i<n-1;i++)
    {
        cin >> dist[i];
    }
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    long long answer = 0LL;
    int start = 0;
    while(start<n-1)
    {
        int x = start;
        start++;
        while(start<n-1)
        {
            if(a[x]>a[start]) break;
            start++;
        }
        long long dsum = 0;
        for(int i=x;i<start;i++)
        {
            dsum += dist[i];
        }
        answer += dsum * a[x];
    }
    cout << answer << '\n';
    return 0;
}
/*
    코드 최적화하기.
*/