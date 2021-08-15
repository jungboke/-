#include <vector>
#include <algorithm>
#include <tuple>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int dx[] = {-1,0,1,1,1,0,-1,-1};
int dy[] = {1,1,1,0,-1,-1,-1,0};
bool check[51][51];
int main(){

    while(true)
    {
        memset(check,false,sizeof(check));
        int n,m;
        cin >> m >> n;
        if(n==0&&m==0) break;
        vector<vector<int>> a(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> a[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] != 0 && check[i][j] == false)
                {
                    count++;
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    check[i][j] = true;
                    while(!q.empty())
                    {
                        int x,y;
                        tie(x,y) = q.front();
                        q.pop();
                        for(int i=0;i<8;i++)
                        {
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx>=0&&nx<n&&ny>=0&&ny<m&&check[nx][ny]==false)
                            {
                                if(a[nx][ny] != 0)
                                {
                                    q.push(make_pair(nx,ny));
                                    check[nx][ny] = true;
                                }
                            }
                        }
                    }    
                }
            }
        }
        cout << count << '\n';
    }
    return 0;
}