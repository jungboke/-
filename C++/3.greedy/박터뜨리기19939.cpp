#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int mini = (m*(m+1))/2;
    if(n<mini) cout << -1 << '\n';
    else
    {
        if((mini-n)%m==0) cout << m-1 << '\n';
        else cout << m << '\n';
    }
    return 0;
}
/*
    그리디답게 아이디어가 중요한 문제. 최소 최대의 차가 최소이면서 그 사이에 있는
    값들을 모두 다르게 한다면, 일단 모든 바구니를 오름차순으로 나열해본다고 생각.
    1씩 증가하는 등차수열의 모습을 하게 됨.
*/