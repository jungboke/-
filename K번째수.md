1
```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> k : commands)
    {
        int c_i = k[0];
        int c_j = k[1];
        int c_k = k[2];
        vector<int> temp(c_j-c_i+1);
        int cnt = 0;
        for(int i=c_i;i<=c_j;i++)
        {
            temp[cnt] = array[i-1];
            cnt++;
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[c_k-1]);
    }
    return answer;
}
```
2
```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++)
    {
        vector<int> temp;
        for(int j=commands[i][0]-1;j<=commands[i][1]-1;j++)
        {
            temp.push_back(array[j]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[commands[i][2]-1]);
    }
    return answer;
}
```