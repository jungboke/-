/*
    배열의 크기때문에 시간제한이 걸릴거같은 문제중, start,end로 범위를 나눌수 있는 문제는
    투포인터로 시도해보기, 위 문제는 같은 경우는 배제해야만 풀수 있음.

    else는 else if보다 훨씬 빠름.
*/
/*
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
    int start = 0;
    int end = n-1;
    int maxi = 0;
    while(start<end)
    {
        //maxi = max(maxi,min(a[start],a[end])*(end-start-1));
        if(a[start]<=a[end])
        {
            int sum = a[start] * (end-start-1);
            if(maxi<sum) maxi = sum;
            start++;
        }
        else if(a[start]>a[end])
        {
            int sum = a[end] * (end-start-1);
            if(maxi<sum) maxi = sum;
            end--;
        }
    }
    cout << maxi << '\n';
    return 0;
}
*/
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i];
//     }
//     int start = 0;
//     int end = n-1;
//     int maxi = 0;
//     while(start<end)
//     {
//         int sum = (end-start-1)*min(a[start],a[end]);
//         if(maxi<sum) maxi = sum;
//         if(a[start]<a[end]) start++;
//         else end--;
//     }
//     cout << maxi << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  int start = 0;
  int end = n-1;
  int maxi = -1;
  while(start<end) {
    int sum = (end-start-1)*min(a[start],a[end]);
    maxi = max(maxi,sum);
    if(a[end]>a[start]) start+=1;
    else end-=1;
  }

  cout << maxi << '\n';
  return 0;
}
