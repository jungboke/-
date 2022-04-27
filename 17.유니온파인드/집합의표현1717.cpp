/*
#include <iostream>
#include <algorithm>
#define rank _rank
using namespace std;
int parent[1000001];
int rank[1000001];
int Find(int x) {
    if (x == parent[x]) {
        return x;
    } else {
        return parent[x] = Find(parent[x]);
    }
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) return;
    if (rank[x] < rank[y]) swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y]) {
        rank[x] = rank[y] + 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=0; i<=n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    while (m--) {
        int w, x, y;
        cin >> w >> x >> y;
        if (w == 0) {
            Union(x, y);
        } else {
            x = Find(x);
            y = Find(y);
            if (x == y) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
}
*/
/*
    Union에서는 랭크조절을 위한 weighted union, Find에서는 경로압축을 하여 유니온파인드 속도증가시키기.
    유니온파인드의 목적은 분리집합(자료구조)을 만드는 것.
*/
/*
#include <vector>
#include <algorithm>
#include <iostream>
#define rank _rank
using namespace std;
int parent[1000001];
int rank[1000001];
int Find(int a)
{
    if(a==parent[a])
        return a;
    else return parent[a] = Find(parent[a]);
}
void Union(int a,int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x==y) return;
    if(rank[x]<rank[y]) swap(x,y);
    parent[y] = x;
    if(rank[x]==rank[y]) rank[x] += 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<=n;i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        if(x==0)
        {
            Union(y,z);
        }
        else
        {
            if(Find(y)==Find(z))
            {
                cout << "YES" << '\n';
            }
            else cout << "NO" << '\n';
        }
    }
    return 0;
}
*/
// #include <vector>
// #include <algorithm>
// #include <iostream>
// #define rank _rank
// using namespace std;
// int parent[1000001];
// int rank[1000001];
// int Find(int num)
// {
//     if(num==parent[num])
//     {
//         return num;
//     }
//     else return parent[num] = Find(parent[num]);
// }
// void Union(int a,int b)
// {
//     int x = Find(a);
//     int y = Find(b);
//     if(x==y) return;
//     if(rank[x]<rank[y]) swap(x,y);
//     parent[y] = x;
//     if(rank[x]==rank[y])
//     {
//         rank[x] += 1;
//     }
// }
// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n,m;
//     cin >> n >> m;
//     for(int i=0;i<=n;i++)
//     {
//         parent[i] = i;
//         //rank[i] = 0;
//     }
//     for(int i=0;i<m;i++)
//     {
//         int x,y,z;
//         cin >> x >> y >> z;
//         if(x==0)
//         {
//             Union(y,z);
//         }
//         else
//         {
//             if(Find(y)==Find(z))
//             {
//                 cout << "YES" << '\n';
//             }
//             else cout << "NO" << '\n';
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define rank _rank
using namespace std;
int parent[1000001];
int rank[1000001];
int Find(int a) {
  if(a==parent[a]) return a;
  else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);
  if(a==b) return;
  if(rank[a]<rank[b]) swap(a,b);
  parent[b] = a;
  if(rank[a]==rank[b]) rank[a]+=1;
}

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,m;
  cin >> n >> m;
  for(int i=0;i<=n;i++) {
    parent[i] = i;
  }
  for(int i=0;i<m;i++) {
    int x,y,z;
    cin >> x >> y >> z;
    if(x==0) Union(y,z);
    else {
      if(Find(y)==Find(z)) {
        cout << "YES" << '\n';
      } else {
        cout << "NO" << '\n';
      }
    }
  }
  return 0;
}
/*
    분리집합은 트리를 만든다고 생각. 전역변수로 생성된 배열은 default로 0값 가짐.
*/