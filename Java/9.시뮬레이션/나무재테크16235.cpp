/*
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
int a[11][11];
int nu[11][11];
vector<int> tree[11][11];
vector<int> dtree[11][11];
void spring(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<tree[i][j].size();k++)
            {
                if(tree[i][j][k]<=a[i][j])
                {
                    a[i][j] -= tree[i][j][k];
                    tree[i][j][k]++;
                }
                else
                {
                    int temp = tree[i][j][k];
                    tree[i][j].erase(tree[i][j].begin()+k);
                    dtree[i][j].push_back(temp);
                    k--;
                }
            }
        }
    }
}
void summer(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int sum = 0;
            for(int k=0;k<dtree[i][j].size();k++)
            {
                sum += dtree[i][j][k]/2;
            }
            a[i][j] += sum;
            dtree[i][j].clear();
        }
    }
}
void fall(int n)
{
    int temp[11][11];
    for(int i=0;i<11;i++)
    {
        for(int j=0;j<11;j++)
        {
            temp[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           for(int k=0;k<tree[i][j].size();k++)
           {
               if(tree[i][j][k]%5==0)
               {
                   for(int z=0;z<8;z++)
                   {
                       int nx = i+dx[z];
                       int ny = j+dy[z];
                       if(nx>=0&&nx<n&&ny>=0&&ny<n)
                       {
                           temp[nx][ny] += 1;
                       }
                   }
               }
           } 
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<temp[i][j];k++)
            {
                tree[i][j].push_back(1);
            }
            sort(tree[i][j].begin(),tree[i][j].end());
        }
    }
}
void winter(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] += nu[i][j];
        }
    }
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] = 5;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> nu[i][j];
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        tree[x-1][y-1].push_back(z);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sort(tree[i][j].begin(),tree[i][j].end());
        }
    }
    while(k--)
    {
        spring(n);
        summer(n);
        fall(n);
        winter(n);
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            answer += tree[i][j].size();
        }
    }
    cout << answer << '\n';
    return 0;
}
*/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
int a[11][11];
int nu[11][11];
vector<int> tree[11][11];
vector<int> dtree[11][11];
void sort_tree(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            sort(tree[i][j].begin(),tree[i][j].end());
        }
    }
}
void spring(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<tree[i][j].size();k++)
            {
                if(a[i][j]>=tree[i][j][k])
                {
                    a[i][j]-=tree[i][j][k];
                    tree[i][j][k]++;
                }
                else
                {
                    dtree[i][j].push_back(tree[i][j][k]);
                    tree[i][j].erase(tree[i][j].begin()+k);
                    k--;
                }
            }
        }
    }
}
void summer(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<dtree[i][j].size();k++)
            {
                a[i][j] += dtree[i][j][k]/2;
            }
            dtree[i][j].clear();
        }
    }
}
void fall(int n)
{
    int temp[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            temp[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<tree[i][j].size();k++)
            {
                if(tree[i][j][k]%5==0)
                {
                    for(int z=0;z<8;z++)
                    {
                        int nx = i+dx[z];
                        int ny = j+dy[z];
                        if(nx>=0&&nx<n&&ny>=0&&ny<n)
                        {
                            temp[nx][ny]+=1;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            while(temp[i][j]--)
            {
                tree[i][j].push_back(1);
            }
        }
    }
}
void winter(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j] += nu[i][j];
        }
    }
}
int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin >> nu[i][j];
            a[i][j] = 5;
        }
    }
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x-=1;y-=1;
        tree[x][y].push_back(z);
    }
    while(k--)
    {
        sort_tree(n);
        spring(n);
        summer(n);
        fall(n);
        winter(n);
    }
    int answer = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            answer += tree[i][j].size();
        }
    }
    cout << answer << '\n';
    return 0;
}
/*
    vector라도 배열형태면 vector1 = vector2 식의 복사불가.
    함수내부에서 배열을 선언할경우 전부 초기화시켜줘야함. 아니면 쓰레기값.
    주변8칸할때 dx,dy값 정확하게 입력하기.
*/