#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
char board[11][11];
int mini = INF;

tuple<int,int,int> move(int x, int y, int idx) {
  int cnt = 0;
  while(true) {
    if(board[x][y]=='O') return make_tuple(-1,-1,cnt);
    if(board[x+dx[idx]][y+dy[idx]]=='#') {
      break;
    } else {
      x += dx[idx];
      y += dy[idx];
      cnt+=1;
    }
  }
  return make_tuple(x,y,cnt);
}

void dfs(int rx, int ry, int bx ,int by, int cnt) {
  if((bx==-1&&by==-1)||cnt==11) return;
  if(rx==-1&&ry==-1) {
    mini = min(mini,cnt);
    return;
  }
  for(int i=0;i<4;i++) {
    int t_rx,t_ry,t_bx,t_by;
    int r_cnt,b_cnt;
    tie(t_rx,t_ry,r_cnt) = move(rx,ry,i);
    tie(t_bx,t_by,b_cnt) = move(bx,by,i);
    if(t_rx!=-1&&t_rx==t_bx&&t_ry==t_by) {
      if(r_cnt>b_cnt) {
        t_rx-=dx[i];
        t_ry-=dy[i];
      } else {
        t_bx-=dx[i];
        t_by-=dy[i];
      }
    }
    dfs(t_rx,t_ry,t_bx,t_by,cnt+1);
  }
}

int main(int argc, char const *argv[])
{
  int n,m;
  cin >> n >> m;
  int rx,ry,bx,by;
  for(int i=0;i<n;i++) {
    string temp;
    cin >> temp;
    for(int j=0;j<m;j++) {
      board[i][j] = temp[j];
      if(board[i][j]=='R') {
        board[i][j] = '.';
        rx = i;
        ry = j;
      } else if(board[i][j]=='B') {
        board[i][j] = '.';
        bx = i;
        by = j;
      }
    }
  }
  dfs(rx,ry,bx,by,0);
  if(mini==INF) cout << -1 << '\n';
  else cout << mini << '\n';
  return 0;
}
