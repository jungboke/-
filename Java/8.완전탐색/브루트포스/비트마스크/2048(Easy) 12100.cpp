#include <bits/stdc++.h>
using namespace std;
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};
int maxi = -1;
int N;

vector<int> gen(int x) {
  vector<int> temp;
  for(int i=0;i<5;i++) {
    int num = (x&3);
    temp.push_back(num);
    x = x>>2;
  }
  return temp;
}

void move(vector<vector<int>> board, vector<int> temp) {
  vector<vector<pair<int,bool>>> d(N,vector<pair<int,bool>>(N));
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      d[i][j].first = board[i][j];
    }
  }
  for(int c=0;c<temp.size();c++) {
    for(int i=0;i<N;i++) {
      for(int j=0;j<N;j++) {
        d[i][j].second = false;
      }
    }
    while(true) {
      bool flag = false;
      if(temp[c]==0) {
        for(int i=0;i<N;i++) {
          for(int j=0;j<N-1;j++) {
            if(d[i][j+1].first==0) continue;
            if(d[i][j].first==0) {
              swap(d[i][j],d[i][j+1]);
              flag = true;
            } else if(d[i][j].first==d[i][j+1].first) {
              if(d[i][j].second==false&&d[i][j+1].second==false) {
                d[i][j].first *= 2;
                d[i][j].second = true;
                d[i][j+1].first = 0;
                flag = true;
              }
            }
          }
        }
      }
      if(temp[c]==1) {
        for(int j=0;j<N;j++) {
          for(int i=0;i<N-1;i++) {
            if(d[i+1][j].first==0) continue;
            if(d[i][j].first==0) {
              swap(d[i][j],d[i+1][j]);
              flag = true;
            } else if(d[i][j].first==d[i+1][j].first) {
              if(d[i][j].second==false&&d[i+1][j].second==false) {
                d[i][j].first *= 2;
                d[i][j].second = true;
                d[i+1][j].first = 0;
                flag = true;
              }
            }
          }
        }
      }
      if(temp[c]==2) {
        for(int i=0;i<N;i++) {
          for(int j=N-1;j>0;j--) {
            if(d[i][j-1].first==0) continue;
            if(d[i][j].first==0) {
              swap(d[i][j],d[i][j-1]);
              flag = true;
            } else if(d[i][j].first==d[i][j-1].first) {
              if(d[i][j].second==false&&d[i][j-1].second==false) {
                d[i][j].first *= 2;
                d[i][j].second = true;
                d[i][j-1].first = 0;
                flag = true;
              }
            }
          }
        }
      }
      if(temp[c]==3) {
        for(int j=0;j<N;j++) {
          for(int i=N-1;i>0;i--) {
            if(d[i-1][j].first==0) continue;
            if(d[i][j].first==0) {
              swap(d[i][j],d[i-1][j]);
              flag = true;
            } else if(d[i][j].first==d[i-1][j].first) {
              if(d[i][j].second==false&&d[i-1][j].second==false) {
                d[i][j].first *= 2;
                d[i][j].second = true;
                d[i-1][j].first = 0;
                flag = true;
              }
            }
          }
        }
      }
      if(flag==false) break;
    }
  }
  for(int i=0;i<N;i++) {
    for(int j=0;j<N;j++) {
      maxi = max(maxi,d[i][j].first);
    }
  }
}

int main(int argc, char const *argv[])
{
  int n;
  cin >> n;
  N=n;
  vector<vector<int>> board(n,vector<int>(n,0));
  for(int i=0;i<n;i++) {
    for(int j=0;j<n;j++) {
      cin >> board[i][j];
    }
  }
  for(int i=0;i<(1<<10);i++) {
    vector<int> temp = gen(i);
    move(board,temp);
  }
  cout << maxi << '\n';
  return 0;
}
