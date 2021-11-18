#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long dist[100001];
vector<long long> result;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    //중간에 벌통
    for(int i=1;i<n-1;i++)
    {
        long long temp = sum-a[0]-a[n-1]+a[i];
        result.push_back(temp);
    }
    //오른쪽 끝 벌통
    long long sum2 = 0;
    for(int i=n-1;i>=0;i--)
    {
        sum2 += a[i];
        dist[i] = sum2 - a[i];
    }
    for(int i=1;i<n-1;i++)
    {
        long long temp = dist[0] + dist[i] - a[i];
        result.push_back(temp);
    }
    //왼쪽 끝 벌통
    long long sum3 = 0;
    for(int i=0;i<n;i++)
    {
        sum3 += a[i];
        dist[i] = sum3 - a[i]; 
    }
    for(int i=1;i<n-1;i++)
    {
        long long temp = dist[n-1] + dist[i] - a[i];
        result.push_back(temp); 
    }
    cout << *max_element(result.begin(),result.end()) << '\n';
    return 0;
}
/*
    왼쪽 끝 꿀통구할때 부분합을 1부터 구해서 값이 이상하게 나옴.
*/