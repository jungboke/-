1
```
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p = 0;
    int y = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'p' || s[i] == 'P') p++;
        if(s[i] == 'y' || s[i] == 'Y') y++;
    }
    if(p == y) answer = true;
    else answer = false;
    return answer;
}
```
2
```
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pcount = 0;
    int ycount = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'p' || s[i] == 'P') pcount++;
        if(s[i] == 'y' || s[i] == 'Y') ycount++;
    }
    if(pcount != ycount) answer = false;
    return answer;
}
```