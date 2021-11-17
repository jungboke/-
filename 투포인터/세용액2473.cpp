#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
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
    long long min = -1;
    int min1 = 0;
    int min2 = 0;
    int min3 = 0;
    for(int i=0;i<a.size()-2;i++)
    {
        int start = i+1;
        int end = a.size()-1;
        while(start<end)
        {
            long long sum = (long long)a[i]+(long long)a[start]+(long long)a[end];
            if(min==-1||min>abs(sum))
            {
                min = abs(sum);
                min1 = i;
                min2 = start;
                min3 = end;
            }
            if(sum>0) end--;
            else if(sum<0) start++;
            else if(sum==0)
            {
                cout << a[i] << ' ' << a[start] << ' ' << a[end] << '\n';
                return 0;
            }
        }
    }
    cout << a[min1] << ' ' << a[min2] << ' ' << a[min3] << '\n';
    return 0;
}
/*
    두용액문제의 상위버전. int형들을 다 더해서 long long으로 만들수 없고 따로 long long으로
    형변환뒤 덧셈을 해줘야함.
*/