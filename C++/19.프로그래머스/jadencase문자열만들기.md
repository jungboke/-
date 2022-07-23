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
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool flag = true;
    for(int i=0;i<s.size();i++)
    {
        if(flag == true)
        {
            s[i] = toupper(s[i]);
            flag = false;
        }
        else s[i] = tolower(s[i]);
        if(s[i] == ' ') flag = true;
    }
    answer = s;
    return answer;
}
```

3

```
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string jaden(string temp) {
    transform(temp.begin(),temp.end(),temp.begin(),::tolower);
    temp[0] = toupper(temp[0]);
    return temp;
}

string solution(string s) {
    string answer = "";
    string temp = "";
    for(int i=0;i<s.size();i++) {
        if(s[i]==' ') {
            answer += jaden(temp);
            temp = "";
            answer += ' ';
        } else temp += s[i];
    }
    answer += jaden(temp);
    return answer;
}
```
