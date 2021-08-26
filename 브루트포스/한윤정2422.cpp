#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool check[201][201];
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> a;
    for(int i=0;i<n;i++) a.push_back(i+1);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        if(x<y) check[x][y] = true;
        else check[y][x] = true;
    }
    int answer = 0;
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            if(check[a[i]][a[j]]==true) continue; 
            for(int k=j+1;k<a.size();k++)
            {
                if(check[a[i]][a[k]]==true||check[a[j]][a[k]]==true) continue;
                answer++;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}
//// 시간복잡도 파악을 못해서 시간초과걸림. 2차원 check배열을 활용하여 안되는 조합을 미리 제외함.
// 조합 내 포함되면 안되는 조합문제는 이렇게 check배열 활용하면 좋을듯함.