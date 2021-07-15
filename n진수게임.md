1
```
#include <string>
#include <vector>
using namespace std;
char num[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string fix(int a, int b)
{
    string temp = "";
    if(a==0)
    {
        temp += num[0];
        return temp;
    }
    while(a!=0)
    {
        temp = num[a%b] + temp;
        a = a/b;
    }
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";
    for(int i=0;i<=t*m;i++)
    {
        result += fix(i,n);
    }
    int count = 0;
    for(int i=p-1;;i+=m)
    {
        answer += result[i];
        count++;
        if(count==t) break;
    }
    return answer;
}
```
2
```

```
+ char배열을 통한 진수변환 사용