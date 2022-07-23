#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int cnt = 0;
    int temp = 0;
    int t = 4;
    while(t--)
    {
        for(int i=1;;i++)
        {
            if(pow(i,2) > n)
            {
                break;
            }
            temp = i;
        }
        n -= pow(temp,2);
        cnt++;
        if(n==0) break;
    }
    cout << cnt << '\n';
    return 0;
}
