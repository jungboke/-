#include <bits/stdc++.h>
#include <cstring>
#define INF 1000000000
using namespace std;
int a[3];
int d[61][61][61];

int go(int x, int y, int z) {
  if(x<0) return go(0,y,z);
  if(y<0) return go(x,0,z);
  if(z<0) return go(x,y,0);
  if(x==0&&y==0&&z==0) return 0;
  if(d[x][y][z]!=-1) return d[x][y][z];
  d[x][y][z] = INF;
  vector<int> temp = {1,3,9};
  do {
    d[x][y][z] = min(d[x][y][z],go(x-temp[0],y-temp[1],z-temp[2])+1);
  } while(next_permutation(temp.begin(),temp.end()));
  return d[x][y][z];
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  for(int i=1;i<=n;i++) {
    cin >> a[i];
  }
  memset(d,-1,sizeof(d));
  cout << go(a[1],a[2],a[3]) << '\n';
  return 0;
}
