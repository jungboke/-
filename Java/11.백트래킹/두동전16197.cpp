#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
char a[21][21];
int answer = INF;
int N,M;

void dfs(int sx1, int sy1, int sx2, int sy2, int cnt) {
  if(cnt==11) {
    return;
  }
  if((sx1==-1&&sy1==-1)||(sx2==-1&&sy2==-1)) {
    if(sx1==-1&&sy1==-1&&sx2==-1&&sy2==-1) {
      return;
    }
    else {
      answer = min(answer,cnt);
      return;
    }
  }  
  for(int i=0;i<4;i++) {
    int ex1 = sx1+dx[i];
    int ey1 = sy1+dy[i];
    int ex2 = sx2+dx[i];
    int ey2 = sy2+dy[i];
    if(!(ex1>=0&&ex1<N&&ey1>=0&&ey1<M)) {
      ex1 = -1;
      ey1 = -1;
    } else if(a[ex1][ey1]=='#') {
      ex1 = sx1;
      ey1 = sy1;
    }
    if(!(ex2>=0&&ex2<N&&ey2>=0&&ey2<M)) {
      ex2 = -1;
      ey2 = -1;
    } else if(a[ex2][ey2]=='#') {
      ex2 = sx2;
      ey2 = sy2;
    }
    dfs(ex1,ey1,ex2,ey2,cnt+1);
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  N=n;M=m;
  int sxy[4] = {0};
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++) {
      a[i][j] = temp[j];
      if(a[i][j]=='o') {
        if(sxy[0]==0&&sxy[1]==0) {
          sxy[0] = i;
          sxy[1] = j;
        } else {
          sxy[2] = i;
          sxy[3] = j;
        }
        a[i][j] = '.';
      }
    }
  }
  dfs(sxy[0],sxy[1],sxy[2],sxy[3],0);
  if(answer==INF) cout << -1 << '\n';
  else cout << answer << '\n';
  return 0;
}