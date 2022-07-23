// end설정하는부분에서 잘못됨. cd의 마지막 인덱스+1까지 취급해야함. why) upperbound관련해서 마지막인덱스 이후로 나올수도
/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
long long a[4][4001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            cin >> a[j][i];
        }
    }
    vector<long long> ab;
    vector<long long> cd;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ab.push_back(a[0][i]+a[1][j]);
            cd.push_back(a[2][i]+a[3][j]);
        }
    }
    sort(ab.begin(),ab.end());
    sort(cd.begin(),cd.end());
    long long answer = 0;
    for(int i=0;i<ab.size();i++)
    {
        long long x = ab[i];
        long long start = 0;
        long long end = cd.size()-1;
        while(start<end)
        {
            long long mid = (start+end)/2;
            long long y = cd[mid];
            if(x+y>=0)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            } 
        }
        long long lower_bound = end;
        start = 0;
        end = cd.size()-1;
        while(start<end)
        {
            long long mid = (start+end)/2;
            long long y = cd[mid];
            if(x+y>0)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }
        long long upper_bound = end;
        answer += (upper_bound-lower_bound);
    }
    cout << answer << '\n';
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n;
//     cin >> n;
//     vector<long long> a(n);
//     vector<long long> b(n);
//     vector<long long> c(n);
//     vector<long long> d(n);
//     for(int i=0;i<n;i++)
//     {
//         cin >> a[i] >> b[i] >> c[i] >> d[i];
//     }
//     vector<long long> e;
//     vector<long long> f;
//     for(int i=0;i<a.size();i++)
//     {
//         for(int j=0;j<b.size();j++)
//         {
//             e.push_back(a[i]+b[j]);
//         }
//     }
//     for(int i=0;i<c.size();i++)
//     {
//         for(int j=0;j<d.size();j++)
//         {
//             f.push_back(c[i]+d[j]);
//         }
//     }
//     sort(e.begin(),e.end());
//     sort(f.begin(),f.end());
//     long long answer = 0;
//     for(int i=0;i<e.size();i++)
//     {
//         auto x = lower_bound(f.begin(),f.end(),-e[i]);
//         auto y = upper_bound(f.begin(),f.end(),-e[i]);
//         answer += y-x;
//     }
//     cout << answer << '\n';
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
vector<int> d;
vector<int> e;
vector<int> f;

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=0;i<n;i++) {
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    a.push_back(A);
    b.push_back(B);
    c.push_back(C);
    d.push_back(D);
  }
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      int temp1 = a[i]+b[j];
      int temp2 = c[i]+d[j];
      e.push_back(temp1);
      f.push_back(temp2);
    }
  }
  sort(e.begin(),e.end());
  sort(f.begin(),f.end());
  long long answer = 0;
  for(int i=0;i<e.size();i++) {
    int temp = e[i];
    auto it1 = lower_bound(f.begin(),f.end(),-temp);
    auto it2 = upper_bound(f.begin(),f.end(),-temp);
    answer += (it2-it1);
  }

  cout << answer << '\n';
  return 0;
}