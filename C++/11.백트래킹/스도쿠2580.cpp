/*
  스도쿠형 백트래킹 문제는 재귀함수의 for문내에
  return이 들어갈 수 있음. 현재의 0이 해결되지 못하면
  다음으로 넘어가면 안되고, return을 해줘야 함.
  재귀함수에서 exit(0) 를 통해 강제종료 가능함.
*/
#include <bits/stdc++.h>
using namespace std;
int board[10][10];
bool col[10][10];
bool row[10][10];
bool blk[4][4][10];

bool num_check(int x, int y, int k) {
  bool flag = true;
  if(row[x][k]==true) flag = false;
  if(col[y][k]==true) flag = false;
  if(blk[x/3][y/3][k]==true) flag = false;
  return flag;
}

void dfs(int cnt, int target) {
  if(cnt==target) {
    for(int i=0;i<9;i++) {
      for(int j=0;j<9;j++) {
        cout << board[i][j] << ' ';
      }
      cout << '\n';
    }
    exit(0);
  }
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      if(board[i][j]!=0) continue;
      for(int k=1;k<=9;k++) {
        if(num_check(i,j,k)) {
          row[i][k] = true;
          col[j][k] = true;
          blk[i/3][j/3][k] = true;
          board[i][j] = k;
          dfs(cnt+1,target);
          board[i][j] = 0;
          blk[i/3][j/3][k] = false;
          col[j][k] = false;
          row[i][k] = false;
        } 
      }
      return;
    }
  }
}

int main(int argc, char const *argv[])
{
  int zero = 0;
  for(int i=0;i<9;i++) {
    for(int j=0;j<9;j++) {
      cin >> board[i][j];
      if(board[i][j]!=0) {
        row[i][board[i][j]] = true;
        col[j][board[i][j]] = true;
        blk[i/3][j/3][board[i][j]] = true;
      } else {
        zero+=1;
      }
    }
  }
  dfs(0,zero);
  return 0;
}