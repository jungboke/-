/*
    점점 수가 커지는 배열을 n등분하여 등분된 부분의 최소최대의 차들의 합을 최소로
    하기 위해 배열의 차들 중 가장 큰 n-1개를 제외한 나머지 합을 구함.
    그림을 그려서 푸는게 이해가 가장 빨랐을듯. 
*/
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
    vector<int> diff;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<n;i++)
    {
        diff.push_back(a[i]-a[i-1]);
    }
    sort(diff.begin(),diff.end(),greater<>());
    int answer = 0;
    for(int i=m-1;i<diff.size();i++)
    {
        answer += diff[i];
    }
    cout << answer << '\n';
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> diff;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++)
    {
        diff.push_back(a[i]-a[i-1]);
    }
    sort(diff.begin(),diff.end());
    int answer = 0;
    for(int i=0;i<diff.size()-m+1;i++)
    {
        answer += diff[i];
    }
    cout << answer << '\n';
    return 0;
}