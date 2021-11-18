/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    int answer = 0;
    for(int i=1;i<m-1;i++)
    {
        int left = -1;
        int right = -1;
        for(int j=0;j<i;j++)
        {
            left = max(left,a[j]);
        }
        for(int j=i+1;j<m;j++)
        {
            right = max(right,a[j]);
        }
        int sum = min(left,right) - a[i];
        if(sum<0) sum = 0;
        answer += sum; 
    }
    cout << answer << '\n';
    return 0;
}*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i=0;i<m;i++)
    {
        cin >> a[i];
    }
    int answer = 0;
    for(int i=1;i<m-1;i++)
    {
        int left = -1;
        int right = -1;
        for(int j=0;j<i;j++)
        {
            left = max(left,a[j]);
        }
        for(int j=i+1;j<m;j++)
        {
            right = max(right,a[j]);
        }
        int x = min(left,right);
        answer += max(0,x-a[i]);
    }
    cout << answer << '\n';
    return 0;
}
/*
    이런종류의 문제는 칸마다 쪼개서 생각해보기.(분할정복)
*/