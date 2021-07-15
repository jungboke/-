1
```
#include <string>
#include <vector>
#include <cctype>
using namespace std;

string solution(string s) {
    s += ' ';
    string answer = "";
    string temp = "";
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == ' ')
        {
            for(int j=0;j<temp.size();j++)
            {
                temp[j] = tolower(temp[j]);
            }
            temp[0] = toupper(temp[0]);
            answer += temp + ' ';
            temp = "";
        }
        else temp += s[i];
    }
    answer.erase(answer.end()-1);
    return answer;
}
```
2
```

```