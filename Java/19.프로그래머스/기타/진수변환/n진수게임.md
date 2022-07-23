- char배열을 통한 진수변환 사용

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
#include <string>
#include <vector>

using namespace std;
char a[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string change(int num,int n)
{
    string temp = "";
    if(num == 0) return "0";
    while(num!=0)
    {
        temp = a[num%n] + temp;
        num = num / n;
    }
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string result = "";
    for(int i=0;i<m*t;i++)
    {
        result += change(i,n);
    }
    for(int i=0;;i++)
    {
        if(i%m==p-1) answer+=result[i];
        if(answer.size()==t) break;
    }
    return answer;
}
```

3

```
#include <string>
#include <vector>

using namespace std;
char a[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
string change(int num,int n)
{
    string temp = "";
    if(num==0) return "0";
    while(num!=0)
    {
        temp = a[num%n] + temp;
        num = num/n;
    }
    return temp;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    string temp = "";
    for(int i=0;i<=m*t;i++)
    {
        temp += change(i,n);
    }
    for(int i=0;i<temp.size();i++)
    {
        if(i%m==p-1) answer+=temp[i];
        if(answer.size()==t) break;
    }
    return answer;
}
```

4

```
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
string result = "";
map<int,char> map1;

string change(int num, int n) {
    if(num==0) return "0";
    string temp = "";
    while(num!=0) {
        int rem = num%n;
        num/=n;
        if(rem>=10) temp = map1[rem] + temp;
        else temp = to_string(rem) + temp;
    }
    return temp;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    map1[10]='A';map1[11]='B';map1[12]='C';map1[13]='D';
    map1[14]='E';map1[15]='F';
    for(int i=0;i<=m*t;i++) {
        result += change(i,n);
    }
    for(int i=0;i<result.size();i++) {
        if(answer.size()==t) break;
        if((i%m)+1==p) answer += result[i];
    }
    return answer;
}
```
