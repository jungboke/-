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
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        int start = 0;
        int end = a.size()-1;
        int mid;
        while(start<=end)
        {
            mid = (start+end)/2;
            if(a[mid]>x) end = mid-1;
            else if(a[mid]<x) start = mid+1;
            else break;
        }
        if(a[mid]!=x) cout << 0 << ' ';
        else cout << 1 << ' ';
    }
    return 0;
}
// 연속되는 정수가 아닌 비연속적인 배열을 상대로 하는 이분탐색(인덱스 활용)